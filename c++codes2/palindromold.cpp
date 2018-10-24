#include<iostream>
#include<cstring>
#include<algorithm>
#include <time.h>
using namespace std;
void output( )
{
    int len,i, count1=0;
    string s;
    cin>>s;
    len=strlen(s.c_str());i=0;
	        while(len--)
	        {
	            char c=s.at(i++)   ;
	            if(c!='0')
	            {
	            size_t no_of_times=count(s.begin(),s.end(),c);
	            replace(s.begin(),s.end(),c,'0');
	            if(no_of_times%2==1)
	                count1++;
	            }
	       }
	    cout<<--count1<<"\n";
    
}
int main()
 {
    clock_t t1,t2;
        t1=clock();
	int x;
	cin>>x;
	while(x--)
	 output( );
	 //cout<<"time="<<clock() - t0;
	 t2=clock();
    float diff ((float)t2-(float)t1);
    float seconds = diff / CLOCKS_PER_SEC;
    cout<<"time(ms)="<<seconds*1000;
	

    
	return 0;
}
