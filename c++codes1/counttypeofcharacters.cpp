#include<iostream>
#include<cstring>
using namespace std;
int main()
 {
     int x,len,l=0,u,n,sp,i;
     string s;
     cin>>x;
     while(x--)
     {
         cin>>s;
         len=s.length();
         l=0;u=0;n=0;sp=0;
         for(i=0;i<len;i++)
         {
            
             if((((int)s.at(i)>=65)&&(((int)s.at(i)<=90))))
               u++;
            
            else if(((int)s.at(i)>=97)&&(((int)s.at(i)<=123)))
               l++;
             
               
            else if((((int)s.at(i)>=48)&&(((int)s.at(i)<=57))))
               n++;
               
             //if((((int)s.at(i)>=1)&&(((int)s.at(i)<=26))))
             else 
               sp++;
               
               
         }
         cout<<u<<"\n"<<l<<"\n"<<n<<"\n"<<sp<<"\n";
         
     }
	
	return 0;
}
