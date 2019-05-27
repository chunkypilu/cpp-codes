#include<bits/stdc++.h>
using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int count1=1,j=0;
int no_threads;
pthread_cond_t c[1000];


void *func1(void *)
{

   int j;
   for(j=1;j<=no_threads;j++)
   {
   
   
    pthread_mutex_lock(&mutex);
    //cout<<"hello";
    //if(count1==i)
     pthread_cond_signal(&c[j]);
    
    pthread_mutex_unlock(&mutex);
    
    }
}



void *func(void *x)
{


    pthread_mutex_lock(&mutex);
    int *number= (int *) x;
    
    int a=*number;
    
   //if(a!=count1) 
   //pthread_cond_wait(&c[i], &mutex);
    
      //cout<<"a= "<<a<<" count1= "<<count1<<endl;
      cout<<"number= "<<*number<<" hello"<<a<<"\n";
      //cout<<"number= "<<j<<" hello"<<"\n";
      count1++;j++;
    pthread_mutex_unlock(&mutex);
    
}

int main()
{

  int x=0,i;
  
  cout<<"Enter no. of threads: ";
  cin>>no_threads;
  
  pthread_t tid[no_threads+1],xtra;
  
  
  
  
  for(i=0;i<=no_threads;i++)
  {  
   if(i==0)
   {
   
   }
     // pthread_create(&tid[i],NULL,&func1,NULL);
      
      
   
   else
    pthread_create(&tid[i],NULL,&func,&i); 
    
    
      
       
  }
  
  
  for(i=1;i<=no_threads;i++)
  {  
  pthread_join(tid[i],NULL); 
  }
  
  
   
return 0;
}
