#include<iostream>
using namespace std;

void printArray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}


void heapify(int arr[],int size, int root)
{
    int right,left;
    right=2*root+2;
    left=2*root+1;
    
    
    if(arr[right]>arr[left])
    {
    
    if((arr[right]>arr[root])&&(right<size))
    {
        swap(arr[right],arr[root]);
        heapify(arr,size,right);
        
    }
    }
    else
    {
    
    
    if((arr[left]>arr[root])&&(left<size))
    {
        swap(arr[left],arr[root]);
        heapify(arr,size,left);
    }
    }
    
    
}


void heapsort(int arr[], int size)
{
    int i;
    for(i=(size-1)/2;i>=0;i--)
    {
        heapify(arr,size,i);
    }
    for(i=size-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}



void swap(int* a,int* b)
{
    int  temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{

    int arr[10]={560 ,901, 164, 664, 43, 572, 955, 811, 733, 542};
    //swap(arr,arr+1);
    //cout<<arr[0]<<" "<<arr[1];
    heapsort(arr,10);
    printArray(arr,10);

    
    return 0;
}
