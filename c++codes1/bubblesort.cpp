#include<iostream>
using namespace std;


int main()
 {
	int t,n;
	cin>>t;

	while(t--)
	{
	    cin>>n;
	    int arr[n],i,j,temp;
	    
	    
	    for(i=0;i<n;i++)
	       {
	        cin>>arr[i];
	       } 
	       
	        
	        
	         for(i=0;i<n;i++)
	         {
	           cout<<arr[i]<<" "; 
	         }
	        
	        cout<<endl;
	   
	   
	   for(j=n-2;j>=0;j--)
	   {
	   
	   
	    for(i=0;i<=j;i++)
	    {
	        if(arr[i]>arr[i+1])
	            {
	                temp=arr[i];
	                arr[i]=arr[i+1];
	                arr[i+1]=temp;
	                
	            }
	    }
	    
	    }
	    
	    for(i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	        
	        cout<<endl;
	   
	    
	        
	        
	}
	return 0;
}
