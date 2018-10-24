//merge sort on linear ring architecture

//this program can sort upto 32 numbers. the input numbers are stored in a linked list

//each thread is capable of sorting two numbers

//initially the input data is distributed over the linear ring architecture amongst all
//the threads giving a list (containing two numbers) to each thread. each thread sorts
//the list they have with them.

//the thread transfers the sorted list to the nearest processor. the nearest processor
//then merges its own sorted list with the received sorted list and transfers this new
//sorted list to the nearest processor waiting for the list. this process continues
//until a complete sorted list is received by thread 0.



#include <iostream>
#define MAX_val 30000
#define no_threads 16
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

using namespace std;

struct LIST
{
    int data;
    struct LIST *next;
};

pthread_mutex_t first_mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t second_mutex=PTHREAD_MUTEX_INITIALIZER;

struct LIST *input=NULL; //to store the input data
struct LIST *input2=NULL; //stores the input data in reverse order for distribution
struct LIST **thread_data;// each thread will have its own list of data
int dist; //this will be used for deciding the nearest processor
void* data_distribution(void *); //this will be used for distributing data amongst threads
int delete_first(struct LIST **);// delete first node of list and return int value
int delete_last(struct LIST **);// delete last node of list and return int value
void add_first(struct LIST **, int); // add at first position of the list
void display(struct LIST *); //display the list
void add_last(struct LIST **,int ); // add at last location of the list
int count_element(struct LIST*); //to count the number of nodes in the list
void* sort1(void*); //this function sorts the list containing two numbers
void* merge_func(void*); //this function merges two sorted lists into a sorted list

int main(int argc,char* argv[])
{
    int N,x,i,*res, phases=0,z;
    char choice;
    //float r;
    cout<<"Enter the no. of elements you want to sort: ";
    cin>>N;
    while(N<2 || N>32)
    {
        if(N<2)
            cout<<"\nAtleast 2 elements required!!";
        else
            cout<<"\nCannot sort more than 32 numbers!!";
        cout<<"\nDo you want to enter again?(Y/N)";
        cin>>choice;
        if(choice=='N'||choice=='n')
            return 0;
        cout<<"Enter the no. of elements you want to sort: ";
        cin>>N;
    }
    input=new struct LIST[N*sizeof(struct LIST)];
    input2=new struct LIST[N*sizeof(struct LIST)];
    res=new int[N*sizeof(int)];
    cout<<"\nEnter numbers:";
    for(i=0;i<N;i++)
    {
        cin>>x;
        add_first(&input,x);
    }
    //r=log(N)/log(2);
    //no_threads=pow(2,((int)ceil(r))-1);
    while(i<2*no_threads)
    {
        add_first(&input,MAX_val);
        i++;
    }
    i=0;
    while(i<2*no_threads)
    {
        z=delete_first(&input);
        add_first(&input2,z);
        i++;
    }
    thread_data=new struct LIST*[(no_threads)*sizeof(struct LIST*)];
    {
        pthread_t processor[no_threads];
        for(i=0;i<no_threads;i++)
        {
            thread_data[i]=NULL;
            pthread_create(&processor[i],NULL,&data_distribution,(void*)&thread_data[i]);
        }
        for(i=0;i<no_threads;i++)
        {
            pthread_join(processor[i],NULL);
        }
    }
    for(i=0;i<no_threads;i++)
    {
        cout<<"\n\n no of data in thread["<<i<<"]:"<<count_element(thread_data[i]);
        display(thread_data[i]);
    }
    //usleep(200000);
    /*
    {
        pthread_t processor[no_threads];
        for(i=0;i<no_threads;i++)
        {
            thread_data[i]=NULL;
            pthread_create(&processor[i],NULL,&sort1,(void*)&thread_data[i]);
        }
        for(i=0;i<no_threads;i++)
        {
            pthread_join(processor[i],NULL);
        }
    }
    cout<<"\n\n after first sorting";
    for(i=0;i<no_threads;i++)
    {
        cout<<"\n\n no of data in thread["<<i<<"]:"<<count_element(thread_data[i]);
        display(thread_data[i]);
    }
    */
    cout<<endl;
    int p_id[no_threads];
    for(i=0;i<no_threads;i++)
    {
        p_id[i]=i;
    }
    phases++;
    {
        dist=-1;
        pthread_t processor[no_threads];
        for(i=2;i<=8;i=i+2)
        {
            pthread_create(&processor[i],NULL,&merge_func,(void*)&p_id[i]);
        }
        for(i=2;i<=8;i=i+2)
        {
            pthread_join(processor[i],NULL);
        }
    }
    /*
    cout<<"\n\n"<<"//////////////////////////////"<<" PHASE "<<phases<<"////////////////////////";
    for(i=0;i<no_threads;i++)
    {
        cout<<"\n\n no of data in thread["<<i<<"]:"<<count_element(thread_data[i]);
        display(thread_data[i]);
    }
    phases++;*/
    {
        pthread_t processor[no_threads];
        dist=1;
        for(i=2;i<=8;i=i+2)
        {
            pthread_create(&processor[no_threads-i+1],NULL,&merge_func,(void*)&p_id[no_threads-i+1]);
        }
        for(i=2;i<=8;i=i+2)
        {
            pthread_join(processor[no_threads-i+1],NULL);
        }
    }
    cout<<"\n\n"<<"//////////////////////////////"<<" PHASE "<<phases<<"////////////////////////";
    for(i=0;i<no_threads;i++)
    {
        cout<<"\n\n no of data in thread["<<i<<"]:"<<count_element(thread_data[i]);
        display(thread_data[i]);
    }
    phases++;
    {
        pthread_t processor[no_threads];
        dist=-2;
        for(i=3;i<8;i=i+4)
        {
            pthread_create(&processor[i],NULL,&merge_func,(void*)&p_id[i]);
        }
        for(i=3;i<8;i=i+4)
        {
            pthread_join(processor[i],NULL);
        }
    }
    /*cout<<"\n\n"<<"//////////////////////////////"<<" PHASE "<<phases<<"////////////////////////";
    for(i=0;i<no_threads;i++)
    {
        cout<<"\n\n no of data in thread["<<i<<"]:"<<count_element(thread_data[i]);
        display(thread_data[i]);
    }
    phases++;*/
    {
        pthread_t processor[no_threads];
        dist=2;
        for(i=3;i<8;i=i+4)
        {
            pthread_create(&processor[i+7],NULL,&merge_func,(void*)&p_id[i+7]);
        }
        for(i=3;i<8;i=i+4)
        {
            pthread_join(processor[i+7],NULL);
        }
    }
    cout<<"\n\n"<<"//////////////////////////////"<<" PHASE "<<phases<<"////////////////////////";
    for(i=0;i<no_threads;i++)
    {
        cout<<"\n\n no of data in thread["<<i<<"]:"<<count_element(thread_data[i]);
        display(thread_data[i]);
    }
    phases++;
    {
    pthread_t processor[no_threads];
    dist=-4;
    pthread_create(&processor[5],NULL,&merge_func,(void*)&p_id[5]);
    pthread_join(processor[5],NULL);
    }
    {
    pthread_t processor[no_threads];
    dist=4;
    pthread_create(&processor[12],NULL,&merge_func,(void*)&p_id[12]);
    pthread_join(processor[12],NULL);
    }
    cout<<"\n\n"<<"//////////////////////////////"<<" PHASE "<<phases<<"////////////////////////";
    for(i=0;i<no_threads;i++)
    {
        cout<<"\n\n no of data in thread["<<i<<"]:"<<count_element(thread_data[i]);
        display(thread_data[i]);
    }
    phases++;
    {
    pthread_t processor[no_threads];
    dist=-1;
    pthread_create(&processor[1],NULL,&merge_func,(void*)&p_id[1]);
    //pthread_join(processor[5],NULL);
    //pthread_join(processor[12],NULL);
    pthread_join(processor[1],NULL);
    }

    cout<<"\n\n"<<"//////////////////////////////"<<"last PHASE "<<phases<<"////////////////////////";
    for(i=0;i<no_threads;i++)
    {
        cout<<"\n\n no of data in thread["<<i<<"]:"<<count_element(thread_data[i]);
        display(thread_data[i]);
    }
    for(i=0;i<N;i++)
    {
        res[i]=delete_first(&thread_data[0]);
    }

    cout<<endl;
    cout<<"//////////////////////////RESULT/////////////////////////////////";
    cout<<"\n";
    for(i=0;i<N;i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}


void* data_distribution(void *x)
{
    struct LIST **temp=(struct LIST **)x;
    int t1,t2;
    pthread_mutex_lock(&first_mutex);
    t1=delete_first(&input2);
    t2=delete_first(&input2);
    add_first(temp,t1);
    add_first(temp,t2);
    sort1((void*)temp);
    pthread_mutex_unlock(&first_mutex);
    return NULL;
}

void add_first(struct LIST **p, int V)
{
    struct LIST *newm;
    newm= new struct LIST; // allocate new mempry to pointer newm
    newm->data=V; // add the data to the node pointed by newm
    newm->next=*p; // modify the link of the node pointed by newm
    *p=newm;
}

void display(struct LIST *start)
{
    int check1=0;
    struct LIST* temp;
    if(start==NULL)
    {
        cout<<"\nList empty!";
    }
    else
    {
        cout<<"\n List of nodes:";
        temp=start;
        while(temp!=NULL)// traverse through all the nodes in the list
        {
            cout<<" "<<temp->data;
            if(temp->next!=NULL)
                cout<<"; ";
            temp=temp->next;
            check1++;
        }
    }
    //cout<<"  check1  "<< check1<<"\n";
}

int delete_first(struct LIST **p)
{
    if(*p==NULL)
    {
        cout<<"List Empty!!! \n";
        return -1;
    }
    else
    {
        int res;
        struct LIST *temp;
        temp=*p;
        res=temp->data;
        *p=temp->next;
        delete(temp); //free the memory utilized by temp
        return res;
    }
}

/*
int delete_last(struct LIST **k)
{
    int m;
    struct LIST *temp;
    temp=*k;
    if(*k==NULL)
    {
        cout<"List Empty!!! \n";
        m=-1;
    }
    else if(temp->next==NULL)
    {
        m=delete_first(k);
    }
    else
    {
        struct LIST *prev=NULL;
        if(temp->next!=NULL)
        {
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        m=temp->data;
        prev->next=NULL;
        delete(temp);
        }
    }
    return m;
}
*/

void add_last(struct LIST **p,int f)
{
    struct LIST *temp;
    temp= new struct LIST;
    temp=*p;
    if (temp==NULL)
    {
        add_first(p,f); // if no node present then call Add-first()
    }
    else
    {
        struct LIST *newm;
        newm=new struct LIST; // allocate new memory to the pointer newm
        newm->data= f; // add the data to the node pointed by newm
        newm->next=NULL; // modify the link of the node pointed by newm
        //if(temp->link!=NULL)
        //{
        while(temp->next!=NULL)// traverse till temp reaches last node
        {
            temp=temp->next;
            //cout<<"akash ";
        }
       // if(temp->link=NULL)
            temp->next=newm;
        //}
    }
}

int count_element(struct LIST *start)
{
    int check1=0;
    struct LIST* temp;
    if(start==NULL)
    {
       return check1;
       // cout<<"List empty!";
    }
    else
    {
        //cout<<"\n List of nodes:";
        temp=start;
        while(temp!=NULL)// traverse through all the nodes in the list
        {
            check1++;
            temp=temp->next;
        }
        return check1;
    }
    //cout<<"  check1  "<< check1<<"\n";
}

void* sort1(void *x)
{
    struct LIST **temp=(struct LIST**)x;
    //int p;
    pthread_mutex_lock(&second_mutex);
    int s[2],swap1;
    for(int i=0;i<2;i++)
    {
        s[i]=delete_first(temp);
    }
    if(s[0]>s[1])
    {
        swap1=s[0];
        s[0]=s[1];
        s[1]=swap1;
    }
    for(int i=1;i>=0;i--)
    {
        add_first(temp,s[i]);
    }
    pthread_mutex_unlock(&second_mutex);
    return NULL;
}

void* merge_func(void *l)
{
    int q,c,i,j,k;
    q=*((int*)l);
    int r1;
    r1=q+dist;
    r1=r1%no_threads;
    c=count_element(thread_data[q]);
    int *r,*s,*t;
    r=new int[c*sizeof(int)];
    s=new int[c*sizeof(int)];
    t=new int[2*c*sizeof(int)];
    for(i=0;i<c;i++)
    {
        r[i]=delete_first(&thread_data[q]);
        s[i]=delete_first(&thread_data[r1]);
    }
    i=0;
    k=0;
    j=0;
    while(i<c && j<c)
    {
        if(r[i]<s[j])
        {
            t[k]=r[i];
            i++;
        }
        else
        {
            t[k]=s[j];
            j++;
        }
        k++;
    }
    if(i==c)
    {
        while(j<c)
        {
            t[k]=s[j];
            j++;
            k++;
        }
    }
    else if(j==c)
    {
        while(i<c)
        {
            t[k]=r[i];
            i++;
            k++;
        }
    }
    for(i=0;i<2*c;i++)
    {
        add_last(&thread_data[r1],t[i]);
    }
    return NULL;
}
