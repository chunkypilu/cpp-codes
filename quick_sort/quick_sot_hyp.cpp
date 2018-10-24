#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include<pthread.h>
#include <unistd.h>
#include<cmath>

using namespace std;

/********************************	Data related variables	************************************************/ 
int size_of_data = 32, no_of_P = 8;
int data[32] = {8,1,4,6,7,5,2,3,10,15,11,187,24,40,51,26,78,62,49,56,27,23,54,48,65,99,55,22,33,44,88,50};

/********************************	Pivot related variables	************************************************/
int *pivot;
bool *pivot_updated;
bool *pivot_selecting_processor;
bool *pivot_terminate_threads;

/********************************	Synchronising threads	************************************************/
pthread_barrier_t b;
pthread_mutex_t myMutex;

pthread_t *p_thread;

struct processor
{
std::vector< int > upper;
std::vector< int > lower;
}*p_mem;
	
void parallel_partition(int id)
{
	int individual_pivot = pivot[id];
	
	if(p_mem[id].upper.size() != 0)
	{ 	
		for (int j = 0 ; j < p_mem[id].upper.size() ; j++)
	    	{
			if(p_mem[id].upper[j] < individual_pivot)
			{		    		
				p_mem[id].lower.push_back(p_mem[id].upper[j]);
				p_mem[id].upper.erase(p_mem[id].upper.begin()+j);		    		
				j--;											
			}
		}	
	}
}

void exchange_data(int id, int phase)
{
	int mask = 1;
	int exchange_node = id ^ (mask << (int)(log2(no_of_P)-phase));	
	//cout << "\n" << id << " -> " << exchange_node;	
	if(exchange_node > id)
	{
		p_mem[exchange_node].upper.insert(p_mem[exchange_node].upper.end(), p_mem[id].upper.begin(), p_mem[id].upper.end());
		p_mem[id].upper.clear();
	}
	else 
	{
		p_mem[exchange_node].lower.insert(p_mem[exchange_node].lower.end(), p_mem[id].lower.begin(), p_mem[id].lower.end());
		p_mem[id].lower.clear();
	}
}

int partition_arry(int id, int p, int r)
{
    int pivot = p_mem[id].upper[r];
    int i = p-1;
    for (int j = p ; j < r; j++)
    {
        if(p_mem[id].upper[j] <= pivot)
        {
            i++;
            int temp = p_mem[id].upper[i];
            p_mem[id].upper[i] = p_mem[id].upper[j];
            p_mem[id].upper[j] = temp;
        }
    }
    int temp = p_mem[id].upper[++i];
            p_mem[id].upper[i] = p_mem[id].upper[r];
            p_mem[id].upper[r] = temp;
    return (i);
}

void quick_sort(int id, int p, int r)
{
    int q;
    if(p<r)
    {
        q = partition_arry(id,p,r);
        quick_sort(id,p,q-1);
        quick_sort(id,q+1,r);
    }
}

void *thread_routine (void *processor_no)
{
	int *id;
	id = (int *)processor_no;
	
	for (int phase = 1; phase <= log2(no_of_P); phase++)
	{
		if((*id+1)%(int)(no_of_P/pow(2,phase-1)) == 0)
		{
			pthread_mutex_lock(&myMutex);
			//cout << "Pivot selecting processor = " << *id << endl;
			if(p_mem[*id].upper.size() == 0)
			{
				pivot_selecting_processor[*id-1] = 1;
				//cout << "Next Pivot selecting processor = " << *id-1 ;		
			}
			else
			{
				for(int i = 0; i < no_of_P/pow(2,phase-1); i++)
				{
					pivot[*id - i] = p_mem[*id].upper[p_mem[*id].upper.size()-1];
					pivot_updated[*id - i] = 1;
					//cout << "\nPivot of processor " << *id-i << "is " << p_mem[*id].upper[p_mem[*id].upper.size()-1];			
				}
				//cout << "\tPivot = " << p_mem[*id].upper[p_mem[*id].upper.size()-1] << endl;
			}			
			pthread_mutex_unlock(&myMutex);
		}
		/*******************************	Wait for Pivot to assign	*******************************************/	
		while(pivot_terminate_threads[*id] == 0)
		{
			if(pivot_updated[*id])
				break;
			if(pivot_selecting_processor[*id])
			{	 
				pthread_mutex_lock(&myMutex);
				//cout << "Pivot selecting processor = " << *id << endl;
				if(p_mem[*id].upper.size() == 0)
				{
					if((*id)%(int)(no_of_P/pow(2,phase-1)) == 0)
					{
						/********************	Terminate threads correspoing to its group****************/
						for(int i = *id + no_of_P/pow(2,phase-1)-1; i > *id; i--)
						{
							int p;				
							//cout << " Thread " << i << " is deleted. Status = " << p << endl;							
							pivot_terminate_threads[i] = 1;
						}
						//cout << " I deleted Threads, My name " << *id << ". Status = " << 0 << endl;
						pivot_terminate_threads[*id] = 1;
					}				
					pivot_selecting_processor[*id] = 0;
					pivot_selecting_processor[*id-1] = 1;
					//cout << "Next Pivot selecting processor = " << *id-1 << endl;		
				}
				else
				{	
					/*****************	Assigning Pivot	**************************************************/
					int a = pow(2,(log2(no_of_P)-phase+1));
					int start_node = a*(1+floor(*id/a))-1;
					for(int i = 0; i < no_of_P/pow(2,phase-1); i++)
					{
						pivot[start_node - i] = p_mem[*id].upper[p_mem[*id].upper.size()-1];
						pivot_updated[start_node - i] = 1;
						//pthread_mutex_lock(&myMutex);					
						//cout << "\nPivot of processor " << start_node-i << "is " << p_mem[*id].upper[p_mem[*id].upper.size()-1];			
						//pthread_mutex_lock(&myMutex);				
					}
					//cout << "\tPivot = " << p_mem[*id].upper[p_mem[*id].upper.size()-1] ;

				}			
				pthread_mutex_unlock(&myMutex);
			}	
		}

		/**********************************	start partitioning	***************************************************/
		parallel_partition(*id);
		pthread_barrier_wait(&b);		//wait for other processor to partition the data
		//cout << "\t Phase " << phase;
		/**********************************	Exchange Data		****************************************************/
		pthread_mutex_lock(&myMutex);	
		exchange_data(*id,phase);
		pthread_mutex_unlock(&myMutex);
		
		pivot_selecting_processor[*id] = 0;
		pivot_updated[*id] = 0;
		pthread_barrier_wait(&b);		//wait for other processor to exchange the data and then go to next phase
		
		if(p_mem[*id].upper.size() == 0 && p_mem[*id].lower.size() != 0 )
		{
			p_mem[*id].upper.insert(p_mem[*id].upper.end(), p_mem[*id].lower.begin(), p_mem[*id].lower.end());
			p_mem[*id].lower.clear();	
		}
		
		/*********************************	Testing Partition	***************************************************/
		//pthread_mutex_lock(&myMutex);
		//cout << "\nProcessor " << *id;// << " pivot " << pivot[*id] << endl;	
		//cout << "\nUpper array ";	
		//for (int i = 0; i<p_mem[*id].upper.size() ; i++)
		//	cout << p_mem[*id].upper[i] << "\t";
		//cout << endl;
		//cout << "\nLower array ";	
		//for (int i = 0; i<p_mem[*id].lower.size() ; i++)
			//cout << p_mem[*id].lower[i] << "\t";
		//pthread_mutex_unlock(&myMutex);
		//cout << "\nEnd of phase " << phase;	
	
		pthread_barrier_wait(&b);
	}
	
	quick_sort(*id,0,p_mem[*id].upper.size()-1);
	pthread_mutex_lock(&myMutex);
	cout << "\nProcessor " << *id;// << " pivot " << pivot[*id] << endl;	
	cout << "\nUpper array ";	
	for (int i = 0; i<p_mem[*id].upper.size() ; i++)
		cout << p_mem[*id].upper[i] << "\t";
	pthread_mutex_unlock(&myMutex);		
	pthread_exit(NULL);
}

int main()
{
	no_of_P = 8;	

	/****************************	Initialize variables	*******************************************************/
	p_mem = new processor[no_of_P];      	
	
	pivot = new int[no_of_P];
	pivot_updated = new bool[no_of_P];
	pivot_selecting_processor = new bool[no_of_P];
	pivot_terminate_threads = new bool[no_of_P];
	p_thread = new pthread_t[no_of_P];
	
	pthread_mutex_init(&myMutex,0);
	pthread_barrier_init(&b, 0, no_of_P);

	/****************************	Assigning Data to each Processor	******************************************/	
	for(int i = 0; i<no_of_P ; i++)
	{
		for(int j=0; j<size_of_data/no_of_P; j++)
		{
			p_mem[i].upper.push_back(data[size_of_data/no_of_P*i + j]);
		}
	}
	
	/****************************	Creating Threads	***********************************************************/
		
	int *name_of_processor	= new int[no_of_P];
	for(int i = 0; i<no_of_P ; i++)
		name_of_processor[i] = i;
	
	int *error = new int[no_of_P];
	for(int i = 0; i<no_of_P ; i++)
	{
		error[i] = pthread_create(&p_thread[i],NULL,thread_routine,(void *)&name_of_processor[i]);
		if(error[i])		
			cout << "\nThread " << i << " Error = " << error[i];
	}


	usleep(10000*1000);			//delay in micro second

	/********************************	Display sorted array	***********************************************/
	cout << "\nSorted array is as follows \n";
	for (int i = 0; i < no_of_P; ++i)
	{
		for(int j = 0; j < p_mem[i].upper.size(); ++j)             
		cout << p_mem[i].upper[j] << "\t"; 
	}
	
	pthread_barrier_destroy(&b);
	pthread_mutex_destroy(&myMutex);
	cout << endl;    
	return 0;
}
