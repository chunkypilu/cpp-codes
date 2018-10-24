#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1;
    string s2("New");
    string s3(" Delhi");
    
    
    s1=s2;
    cout<<"s1= "<<s1<<"\n";
    
    s1="standard c++";
    cout<<"Now s1= "<<s1<<"\n";
    
    string s4(s1);
    cout<<"s4= "<<s4<<"\n";
    
    cout<<"Enter a string\n";
    cin>>s4;
    
    cout<<"Now s4= "<<s4<<"\n";
    
    s1=s2+s3;
    cout<<"s1 finally contains: "<<s1<<"\n";
    return 0;
}
