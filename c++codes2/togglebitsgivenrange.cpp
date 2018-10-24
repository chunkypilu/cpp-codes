#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>
using namespace std;
vector<int> dec_to_bin(int a)
{
    
    vector <int> v;
    while(a!=0)
    {
        v.push_back(a%2);
        a=a/2;
    }
    reverse(v.begin(), v.end());
    return v;
    
      
}

int bin_to_dec(vector<int> &v2)
{
      int dec_val=0,i;
      for(i=0;i<v2.size();i++)
      {
        dec_val=dec_val+v2[i]*pow(2,v2.size()-i-1);
      }
   return dec_val;

}

int main()
 {  
     int x,N,L,R,i;
     vector <int> v1;
     cin>>x;
     while(x--)
     {   N=0;L=0;R=0;i=0; 
         cin>>N>>L>>R;
         v1=dec_to_bin(N);
           
           for(i=v1.size()-R;i<=v1.size()-L;i++)
           {
                  if(v1[i]==0)
                      v1[i]=1;
                  else
                     v1[i]=0;    
           }
         cout<<bin_to_dec(v1)<<"\n";
     }
	return 0;
}
