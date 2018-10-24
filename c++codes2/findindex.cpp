#include<iostream>
using namespace std;
int main()
 {
	int x,no_elements,i=0,key,k;
	cin>>x;
	while(x--)
	{   i=0;
	    cin>>no_elements;
	    int arr[no_elements];
	    k=no_elements;
	    while(no_elements--)
	    {
	        cin>>arr[i];
	        i++;
	        
	    }
	    cin>>key;
	    for(i=0;i<k;i++)
	    {
	        if(arr[i]==key)
	             {
	              cout<<i<<"\t";
	              break;
	             }
	    }
	    for(i=k-1;i>=0;i--)
	    {
	        if(arr[i]==key)
	              {
	              cout<<i<<"\n";
	              break;
	              }
	    }
	    
	}
	return 0;
}
