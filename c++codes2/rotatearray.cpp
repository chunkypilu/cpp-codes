#include<iostream>
using namespace std;
void rotateLeft(int a[],int size,int k)
{
    int i;
    int b[size];
    for(i=0;i<size;i++)
        b[i]=a[i];
    
    for(i=size-1;i>=0;i--)
    {
        a[i]=b[(i+k)%size];
    }
}


void rorateRight(int a[],int size, int k)
{
    int b[size],i;
    for(i=0;i<size;i++)
        b[i]=a[i];

    for(i=0;i<size;i++)
    {   
        a[i]=b[((i-k)<0)?(i-k+size):(i-k)];
    }
}

void printArray(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{   
    int a[]={1,2,3,4};
    int size=sizeof(a)/sizeof(a[0]);
    rotateLeft(a,size,2);
    printArray(a,size);
    cout<<endl;
    rorateRight(a,size,2);
    printArray(a,size);   
    return 0;
}
