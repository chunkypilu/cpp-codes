#include<iostream>
using namespace std;

long fact (int n)
  {
    if(n==0)
        return 1;
    
    return (n*fact(n-1)); 
  
  }
  
int main()
 {
    int number;
    
    cout<<"Enter a positive number:\n";
    cin>>number;
    
    cout<<"Factorial of "<<number<<" is "<<fact(number);
    return 0;      
 }  

