#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<int> dec_to_bin(int a)
{
    
    vector <int> v;
    while(a!=0)
    {
        v.push_back(a%2);
        a=a/2;
    }
    //reverse(v.begin(), v.end());
    return v;
    
      
}


int main()
{   
    int x,i;
    cin>>x;
    vector <int> v1,v2;
    while(x--)
    {
        int m,n,diff_size;
        cin>>m>>n;
        v1=dec_to_bin(m);
        v2=dec_to_bin(n);
        v2.resize(v1.size());
        for(i=v2.size();i<v2.size()+diff_size;i++)
            {
                v2.push_back(0);               
            }

        for(i=0;i<v2.size();i++)
        {
            if(v1[i]!=v2[i])
                 break;
                 
        }
        cout<<i+1<<endl;
        
        
    }


    return 0;
    
}
