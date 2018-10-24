#include<bits/stdc++.h>
using namespace std;

char  mfset_c[500];
int setsize=0;
void INITIAL(char x, int i)
{
       mfset_c[i]=x;
       setsize++;
}

char FIND(int x)
{
    return mfset_c[x];
}

void MERGE(int a,int b)
{
    
    char a1=mfset_c[a],b1=mfset_c[b];
    int i;
    for(i=1;i<=setsize;i++)
    {
         if(mfset_c[i]==b1)
            mfset_c[i]=a1;
    }
}

void printMfset()
{
    int i;
    for(i=1;i<=setsize;i++)
       cout<<mfset_c[i]<<" ";
}



////cd /media/priyank/New\ Volume/M\ Tech/ctech/3rd\ SEM/ELL781/Assignment3
