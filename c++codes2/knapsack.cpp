#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t,n,w,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>w;
        int val[n],wt[n];
        map<int,int> mymap;
        
        for(i=0;i<n;i++)
        {
          //mymap.insert(val[i],wt[i]);
         cin>>val[i];
        }
        
        for(i=0;i<n;i++)
        {
          //mymap.insert(val[i],wt[i]);
          cin>>wt[i];
        }
        
        
             
        for(i=0;i<n;i++)
        {
          //mymap.insert(val[i],wt[i]);
          mymap[val[i]]=wt[i];
        }
        
        map<int,int>::reverse_iterator it;
        
        
        int sum_val=0,sum_wt=0;
        for(it=mymap.rbegin();it!=mymap.rend();it++)
        {
               cout<<(*it).first<<" "<<(*it).second<<endl;
               //cout<<it
               
               if(((sum_wt+(*it).second)<=w)&&(*it).second<=w)
               {
                    sum_wt+=(*it).second;
                    sum_val+=(*it).first;
               }
                
        } 
        
        cout<<sum_val<<endl;
    
    
    }
    
   
   
   
    
    
    return 0;
} 


/*
Input:
58
41
57 95 13 29 1 99 34 77 61 23 24 70 73 88 33 61 43 5 41 63 8 67 20 72 98 59 46 58 64 94 97 70 46 81 42 7 1 52 20 54 81 3 73 78 81 11 41 45 18 94 24 82 9 19 59 48 2 72 
83 84 85 76 13 87 2 23 33 82 79 100 88 85 91 78 83 44 4 50 11 68 90 88 73 83 46 16 7 35 76 31 40 49 65 2 18 47 55 38 75 58 86 77 96 94 82 92 10 86 54 49 65 44 77 22 81 52 

Its Correct output is:
223

And Your Output is:
182

*/
