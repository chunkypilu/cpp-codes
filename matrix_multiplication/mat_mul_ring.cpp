#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include<vector>
using namespace std;
int row1,row2,col1,col2;
int p;
vector <vector <int> > C;
vector <vector <int> > A;
vector <vector <int> > B;
pthread_mutex_t lock;
struct S
{
 int pid;
 int row_st_id;
 int col_st_id;
 int dup_col_st_id;
 int rc;
 int cc;
 int dup_cc;
 vector < vector <int> > ro;
 vector <vector <int> > col;
 vector<vector <int> > copy;
};

struct S* a;

pthread_barrier_t bar;
int ctrl=0;

void* mm(void *b)
{
 struct S* w=(struct S*)b;
 int index=(w->pid);
 *(a+index)=*w;
 int l,m,n;

int phase;
for(phase=0;phase<p;phase++)
{
 for(l=0;l<(a+w->pid)->rc;l++)
 {
   for(m=0;m<(a+w->pid)->cc;m++)
    {
       for(n=0;n<row2;n++)
         {
            C[l+(a+w->pid)->row_st_id][m+(a+w->pid)->col_st_id]=C[l+(a+w->pid)->row_st_id][m+(a+w->pid)->col_st_id]+(a+w->pid)->ro[l][n]*(a+w->pid)->col[n][m];

         }
    }
  }



pthread_barrier_wait(&bar);

(a+w->pid)->copy=(a+(w->pid+1)%p)->col;
(a+w->pid)->dup_col_st_id=(a+(w->pid+1)%p)->col_st_id;
(a+w->pid)->dup_cc=(a+(w->pid+1)%p)->cc;
pthread_barrier_wait(&bar);

(a+w->pid)->col=(a+w->pid)->copy;
(a+w->pid)->col_st_id=(a+w->pid)->dup_col_st_id;
(a+w->pid)->cc=(a+w->pid)->dup_cc;
pthread_barrier_wait(&bar);
 }
}



int main(int argc,char* argv[])
{

int check=1;int i,j;
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

while(check)
{
if(row2!=col1)
cout<<"Sizes are incompatible,matrix multiplication not possible";
else
{
check=0;
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
  C[i].resize(col2);
  for(j=0;j<col2;j++)
   {
    C[i][j]=0;
   }
 }

//task distr.
int td_r[p];
int td_c[p];
//assigning the rows
for(i=0;i<p;i++)
{
 td_r[i]=(row1/p);
}
int mod=(row1%p);
for(i=0;i<mod;i++)
td_r[i]=td_r[i]+1;


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
long thread;
pthread_barrier_init(& bar,NULL,p); //
pthread_t* thread_handles;
thread_handles=(pthread_t*)malloc(sizeof(pthread_t)*p);
pthread_mutex_init(&lock,NULL);
//Task assignment and thread generation
int r_count=0,c_count=0;
for(i=0;i<p;i++)
{

 (z+i)->pid=i;
 (z+i)->rc=td_r[i];
 (z+i)->cc=td_c[i];

if(i==0)
{
 (z+i)->row_st_id=0;
 (z+i)->col_st_id=0;
}
else
{
 (z+i)->row_st_id=(z+i-1)->row_st_id+td_r[i-1];
 (z+i)->col_st_id=(z+i-1)->col_st_id+td_c[i-1];
}

//copying data

(z+i)->ro.resize((z+i)-> rc);
for(int m=0;m<(z+i)-> rc;m++)
{
 (z+i)->ro[m].resize(col1);
 for(int n=0;n<col1;n++)
  {
   (z+i)->ro[m][n]=A[m+r_count][n];
  }
}
r_count=r_count+(z+i)->rc;

int m,n;
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
cout<<"\n Output Matrix C is as Follows:\n";

for(i=0;i<row1;i++)
{
 for(j=0;j<col2;j++)
 {
  cout<<C[i][j]<<"\t";
 }
  cout<<endl;
}
pthread_barrier_destroy(&bar);
pthread_mutex_destroy(&lock);
return 0;
}








