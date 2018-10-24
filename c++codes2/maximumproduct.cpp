#include<iostream>
#include <algorithm>

// implement BigInteger class or use java's built in class

using namespace std;
int main()
 {
	int x,size,k,i;
	cin>>x;
	while(x--)
	{
	    cin>>size;
	    cin>>k;
	    long int arr[size];
	    long double product=1;
	    for(i=0;i<size;i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr, arr + size,greater<int>());
	    while(k--)
	    {
	        product=product*arr[k];
	    }
	    cout<<product<<"\n";
	    
	}
	return 0;
}
