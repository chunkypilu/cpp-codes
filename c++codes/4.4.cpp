#include<iostream>
using namespace std;

void TOH(int d,char tower1,char tower2,char tower3)
    {
        if(d==1)
        {
            cout<<"\nshift top disk from tower"<<tower1<<" to "<<tower2;
            return;
        }
        
        TOH(d-1,tower1,tower3,tower2);
        cout<<"\nshift top disk from tower "<<tower1<<" to tower"<<tower2;
        
        TOH(d-1,tower3,tower2,tower1);
    }
    
int main()
    {
        int disk;
        
        cout<<"Enter no. of disks:";
        cin>>disk;
        
        if(disk<1)
            cout<<"\n There are no disks to shift";
        else
            cout<<"\nThere are "<<disk<<" disks in tower1";
            
        TOH(disk,'1','2','3');
        cout<<"\n\n"<<disk<<"disks in tower1 are shifted tower2\n";    
    
        return 0;   
    }
