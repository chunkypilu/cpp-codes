#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include<vector>
#include<math.h>
using namespace std;
int row1,row2,col1,col2;
int p;
vector <vector <int> > A;
vector <vector <int> > B;
vector <vector <int> > C;

int N=2;
int power(int,int);
int power(int base,int expo)
{
 int result=1;
 int r;
 for(r=0;r<expo;r++)
  {
    result=result*base;
  }

return result;
}

 
struct S
{
 int pid;         //thread number.
 int col_st_id;  //column starting no.
 int cc;   // no. of columns assigned to a particular processor
 vector < vector <int> > ro;  //row elements
 vector <vector <int> > col;  //column elements
 int check;
 int token;
};

struct S* a;

pthread_barrier_t bar;
int ctrl=0;

void* mm(void *b)
{

struct S* w=(struct S*)b;
int index=(w->pid);

*(a+w->pid)=*w;
int l,m,n;
pthread_barrier_wait(&bar);
int d=log(p)/log(2);
int phase=0;
while(phase<d)
{
 if((a+w->pid)->check==1)
  {
    
   for(l=0;l<row1;l++)
   {
    for(m=0;m<(a+w->pid)->cc;m++)
    {
     for(n=0;n<row2;n++)
      {
       C[l][m+(a+w->pid)->col_st_id]=C[l][m+(a+w->pid)->col_st_id]+(a+w->pid)->ro[l][n]*(a+w->pid)->col[n][m];

      }
    }
    
   }
   
   (a+w->pid)->token=1;
  }



pthread_barrier_wait(&bar);
if(phase<d)
{
 if((a+w->pid)->token==1)
 {
  if((a+w->pid+power(N,phase))->cc>0)
  {
   (a+w->pid+power(N,phase))->ro=(a+w->pid)->ro;
   (a+w->pid+power(N,phase))->check=1;
  }
  (a+w->pid)->check=0;
 }
}
pthread_barrier_wait(&bar);
phase++;

}
}



int main(int argc,char* argv[])
{


int checking=1;int i,j;
while(checking)
{
cout<<"enter the number of rows of Mat1"<<endl;
cin>>row1;
cout<<"enter the number of columns of Mat1"<<endl;
cin>>col1;
cout<<"enter the number of rows of Mat2"<<endl;
cin>>row2;
cout<<"enter the number of columns of Mat2"<<endl;
cin>>col2;

cout<<"Enter the number of threads";
cin>>p;
 if(row2!=col1)
  {
    cout<<"Sizes are incompatible,matrix multiplication not possible \n";
  }
 else
  {
  checking=0;

  cout<<"Enter the elements of matrix 1\n";
  A.resize(row1);
for(i=0;i<row1;i++)
{
 A[i].resize(col1);
  for(j=0;j<col1;j++)
  {
   cout<<"enter the element A["<<i<<"]["<<j<<"]"<<"\t";
   cin>>A[i][j];
  }
cout<<"\n";
}

cout<<"Enter the elements of matrix 2\n";
B.resize(row2);
for(i=0;i<row2;i++)
{
B[i].resize(col2);
  for(j=0;j<col2;j++)
  {
   cout<<"enter the element B["<<i<<"]["<<j<<"]"<<"\t";
   cin>>B[i][j];
    
  }
   cout<<"\n";
  }
 }
}
//---------initialization of C matrix--------
C.resize(row1);
for(i=0;i<row1;i++)
 {
  C[i].resize(col1);
  for(j=0;j<col2;j++)
   {
    C[i][j]=0;
   }
 }

//task distr.

int td_c[p];

int mod;
for(i=0;i<p;i++)
{
 td_c[i]=(col2/p);
}
mod=(col2%p);
for(i=0;i<mod;i++)
td_c[i]=td_c[i]+1;


struct S *z;
z=(struct S*)malloc(p*sizeof(struct S));
a=(struct S*)malloc(p*sizeof(struct S));
int thread;
pthread_barrier_init(& bar,NULL,p); //
pthread_t* thread_handles;
thread_handles=(pthread_t*)malloc(sizeof(pthread_t)*p);
//Task assignment and thread generation
int c_count=0;
int m,n;
for(i=0;i<p;i++)
{

 (z+i)->pid=i;
 (z+i)->cc=td_c[i];

if(i==0)
{

 (z+i)->col_st_id=0;
}
else
{
 (z+i)->col_st_id=(z+i-1)->col_st_id+td_c[i-1];
}


//copying data
if(i==0)
{
 (z+i)->ro.resize(row1);
 for(m=0;m<row1;m++)
 {
 (z+i)->ro[m].resize(col1);
   for(n=0;n<col1;n++)
   {
   (z+i)->ro[m][n]=A[m][n];
   }
 }
 (z+i)->check=1;
 (z+i)->token=1;
}

if(i!=0)
{
 (z+i)->check=0;
 (z+i)->token=0;
}
 (z+i)->col.resize(row2);
 for( m=0;m<row2;m++)
 {
  (z+i)->col[m].resize((z+i)->cc);
  for( n=0;n<((z+i)->cc);n++)
  {
  (z+i)->col[m][n]=B[m][n+c_count];
  }
 }
c_count=c_count+(z+i)->cc;

pthread_create(&thread_handles[i],NULL,mm,(void*)(z+i)); //creating threads

}

for(i=0;i<p;i++)
{
  pthread_join(thread_handles[i],NULL);
}
free(thread_handles);
//-------------Displaying the Calculated Matrix-------------


cout<<"\nMatrix A is as Follows:\n";

for(i=0;i<row1;i++)
{
 for(j=0;j<col2;j++)
 {
  cout<<A[i][j]<<"\t";
 }
  cout<<endl;
}

cout<<"\n Matrix B is as Follows:\n";

for(i=0;i<row1;i++)
{
 for(j=0;j<col2;j++)
 {
  cout<<B[i][j]<<"\t";
 }
  cout<<endl;
}


cout<<"\n Matrix C is as Follows:\n";

for(i=0;i<row1;i++)
{
 for(j=0;j<col2;j++)
 {
 cout<<C[i][j]<<"\t";
 }
 cout<<endl;
}
pthread_barrier_destroy(&bar);
return 0;
}
