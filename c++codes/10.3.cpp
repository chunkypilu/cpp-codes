#include<iostream>
#include<string>
#include <cstring>
using namespace std;

void fnc (int a[10][10]) {}

int main()
{

    int** a;
    
    fnc(a);
    return 0;

    char string1[100]="C++";
    char string2[100]="Programming";
    
   // string1 = string2;
    
    int m=strlen(string1);
    int n=strlen(string2);
    
    cout << m << " " << n << endl; return 9;
    
    for (int i=1;i<n;i++)
    {
        cout.write(string2,i);
        cout<<"\n";
    }
    
    for(int i=n;i>0;i++)
    {   
        cout.write(string2,i);
        cout<<"\n";
    
    }
    
    cout.write(string1,m).write(string2,n);
    cout<<"\n";
    
    cout.write(string1,10);
    return 0;
}

