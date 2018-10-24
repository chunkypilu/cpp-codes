#include<iostream>
using namespace std;
int main()
{
	short number;
	cout<<"Enter a number:";
	cin>>number;
	cout<<"The factorial of"<<number<<"is";
	int accumulator=1;
	for(;number>0;accumulator*=number --);
	if(number<0)
 		cout<<"neg number"<<".\n";
 	else
 	 	cout<<accumulator<<".\n";
return 0;

}
