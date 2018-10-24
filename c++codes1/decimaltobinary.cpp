#include <iostream>
using namespace std;

void convert(int x)
{
    int queo,rem,a[10],i;
    for( i=0;queo!=0;i++)
    {
        queo=x/2;
        rem=x%2;
        x=queo;
        a[i]=rem;
    }
    for(int j=i-1;j>=0;j--)
    {
        cout<<a[j];
    }
}


int main() {
    
	convert(5);
	return 0;
}
