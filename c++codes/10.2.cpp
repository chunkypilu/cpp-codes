#include<iostream>
using namespace std;
int main()
{
    int size=20;
    char city[20];
    
    cout<<"Enter city name: \n";
    cin>>city;
    cout<<"City name: "<<city<<"\n\n";
    
    cout<<"Enter city name again: \n";
    cin.getline(city,size);
    cout<<"city name now: "<<city<<"\n\n";
    
    cout<<"Enter another city name: \n";
    cin.getline(city,size);
    cout<<"new city name: "<<city<<"\n\n";
    
    return 0;
}
