#include<iostream>
#include<cmath>
using namespace std;

int uglyNumber(int x)
{
    int ugly[x],i2,i3,i5,i;
    ugly[0]=1;
    int next_mul_of_two=2,next_mul_of_three=3,next_mul_of_five=5,next_ugly_number=1;
    i2=i3=i5=0;
    for(i=1;i<x;i++)
    {
        next_ugly_number=min(min(next_mul_of_two,next_mul_of_three),next_mul_of_five);
        ugly[i]=next_ugly_number;
        
        if(next_ugly_number%2==0)
        {
            i2++;
            next_mul_of_two=ugly[i2]*2;
        }
        if(next_ugly_number%3==0)
        {
            i3++;
            next_mul_of_three=ugly[i3]*3;
            
        }
        
        if(next_ugly_number%5==0)
        {
            i5++;
            next_mul_of_five=ugly[i5]*5;
            
            
        }
        
        }
        return ugly[x-1];
        
    }




int main()
{
    int x;
    cin>>x;
    cout<<"answer="<<uglyNumber(x);   
    

    return 0;
}
