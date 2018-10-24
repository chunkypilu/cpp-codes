#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <pthread.h>
#include <unistd.h>
#include <cmath>
#include <limits.h>

using namespace std;

/********************************	Data related variables	******************************************/ 
int size_of_data = 10, no_of_P = 8;
//int data[10];
//int data[41] = {8,1,4,6,7,5,2,3,10,15,11,187,24,40,51,26,78,62,49,56,27,23,54,48,65,99,55,22,33,44,37,99,36,47,993,636,357,3663,677,55,381};
int data[10] = {4,1,5,7,3,9,6,2,8,10};
/********************************	Pivot related variables	 **********************************************/
int *pivot;
int *from;
bool *pivot_updated;
bool *pivot_selecting_processor;

/********************************	Synchronising threads	************************************************/
pthread_barrier_t b;
pthread_mutex_t myMutex;

pthread_t *p_thread;

struct processor
{
std::vector< int > upper;
std::vector< int > lower;
std::vector< int > receiver_one;
std::vector< int > receiver_two;
}*p_mem;

/********************   upper and lower   **********************/	
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


/******************   communication   *************************/
void exchange_data(int id, int phase)
{
	int cnst = (int)pow(2,log2(no_of_P)-phase+1);

	if(id%cnst < cnst/2)
	{
		p_mem[id].receiver_one = p_mem[id].upper;
		p_mem[id].upper.clear();
	}
	pthread_barrier_wait(&b);
	for(int i=0; i<cnst/2; i++)
	{
		if(id%cnst != (cnst-1))
		{
			p_mem[id+1].receiver_two = p_mem[id].receiver_one;
			p_mem[id].receiver_one.clear();
		}

			pthread_barrier_wait(&b);
		

			p_mem[id].receiver_one = p_mem[id].receiver_two;
			p_mem[id].receiver_two.clear();

			pthread_barrier_wait(&b);
	}
	pthread_barrier_wait(&b);


	if(id%cnst >= cnst/2)
	{
		p_mem[id].receiver_two = p_mem[id].lower;
		p_mem[id].lower.clear();
		p_mem[id].lower = p_mem[id].receiver_one;
		p_mem[id].receiver_one.clear();
	}
	pthread_barrier_wait(&b);

	for(int i=0; i<cnst/2; i++)
	{
		if(id%cnst != 0)
		{


			p_mem[id-1].receiver_one = p_mem[id].receiver_two;
			p_mem[id].receiver_two.clear();

		}
			pthread_barrier_wait(&b);
		

			p_mem[id].receiver_two = p_mem[id].receiver_one;
			p_mem[id].receiver_one.clear();

			pthread_barrier_wait(&b);
	}

	pthread_barrier_wait(&b);	

	if(id%cnst < cnst/2)
	{
		p_mem[id].upper = p_mem[id].receiver_two;
		p_mem[id].receiver_two.clear();
	}
	pthread_barrier_wait(&b);

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
	int *id, cnst;
	id = (int *)processor_no;
	
	for (int phase = 1; phase <= log2(no_of_P); phase++)
	{

		/*****************  Pivot select & broadcast  ********************/
		cnst = (int)pow(2,log2(no_of_P)-phase+1);
		if((*id-(int)(no_of_P/(int)pow(2,phase)))%cnst == 0)   //for the middle one
		{

			pthread_mutex_lock(&myMutex);
			if(p_mem[*id].upper.size() == 0)
			{
				pivot_selecting_processor[*id-(no_of_P/(int)pow(2,phase))] = 1;

			}
			else
			{

				pivot[*id-1] = p_mem[*id].upper[p_mem[*id].upper.size()-1];
				pivot[*id] = p_mem[*id].upper[p_mem[*id].upper.size()-1];
				pivot_updated[*id-1] = 1;
				pivot_updated[*id] = 1;
				from[*id] = *id;
				from[*id-1] = *id;
			}
			pthread_mutex_unlock(&myMutex);
		}

		while(pivot_selecting_processor[*id]==0 && pivot_updated[*id]==0); //reset everything at the end

		if(pivot_updated[*id] == 1 && (*id%cnst!=0 && *id%cnst!=(cnst-1)))
		{

			//distribute.
			if(*id-from[*id] == -1)
			{
				pivot[*id-1] = pivot[*id];
				from[*id-1] = *id;
				pivot_updated[*id-1] = 1;
			}
			else if(*id-from[*id] == 1 || *id-from[*id] == 0)
			{
				pivot[*id+1] = pivot[*id];
				from[*id+1] = *id;
				pivot_updated[*id+1] = 1;
			}
		}
		else if(pivot_selecting_processor[*id] == 1)
		{
			//check if available, assign distribute sequentially, else +1 and leave
			if(p_mem[*id].upper.size() != 0)
			{
				pivot[*id] = p_mem[*id].upper[p_mem[*id].upper.size()-1];
				pivot[*id+1] = pivot[*id];
				from[*id+1] = *id;
				pivot_updated[*id+1] = 1;
			}
			else
			{
				//tell next P to select a pivot and stand aside
				pivot_selecting_processor[*id+1] = 1;
			}
		}



		//partition, exchange data
		
		/*********** partition and wait ***********/
		parallel_partition(*id);

		pivot_selecting_processor[*id] = 0;
		from[*id] = INT_MAX;
		pivot_updated[*id] = 0;

		pthread_barrier_wait(&b);		//wait for other processor to partition the data


		/*************** exchange data *****************/
		exchange_data(*id, phase);

		pthread_barrier_wait(&b);		
		pivot_selecting_processor[*id] = 0;
		pivot_updated[*id] = 0;
		from[*id] = INT_MAX;
				//wait for other processor to exchange the data and then go to next phase
		

		if(p_mem[*id].lower.size() != 0 )
		{
			p_mem[*id].upper.insert(p_mem[*id].upper.end(), p_mem[*id].lower.begin(), p_mem[*id].lower.end());
			p_mem[*id].lower.clear();	
		}
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
	from = new int[no_of_P];
	p_thread = new pthread_t[no_of_P];
	
	pthread_mutex_init(&myMutex,0);
	pthread_barrier_init(&b, 0, no_of_P);

	/****************************	Assigning Data to each Processor	******************************************/	
	for(int i = 0; i<(size_of_data%no_of_P) ; i++)
	{
		for(int j=0; j<(int)floor(size_of_data/no_of_P)+1; j++)
		{
			p_mem[i].upper.push_back(data[i*(int)(floor(size_of_data/no_of_P)+1) + j]);
		}
	}
	for(int i = (size_of_data%no_of_P); i<no_of_P; i++)
	{
		for(int j=0; j<(int)floor(size_of_data/no_of_P); j++)
			p_mem[i].upper.push_back(data[(size_of_data%no_of_P)+i*(int)floor(size_of_data/no_of_P) + j]);
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


	for(int i=0; i<no_of_P; i++)
	{
		pthread_join(p_thread[i],NULL);
	}

//	usleep(10000*1000);			//delay in micro second

	/********************************	Display sorted array	***********************************************/
	cout << "\nSorted array is as follows \n";
	for (int i = 0; i < no_of_P; i++)
	{
		for(int j = 0; j < p_mem[i].upper.size(); j++)             
		cout << p_mem[i].upper[j] << "\t"; 
	}
	
	pthread_barrier_destroy(&b);
	pthread_mutex_destroy(&myMutex);
	cout << endl;    
	return 0;
}
