#include<iostream>
using namespace std;

int main()
{   
//    char arr2[8]={'b','a','c','x','b','d','c','d'},  arr1[4]={'a','b','c','d'};
    int x;
    cin>>x;
    while(x--)
    {
    int i,j,k,l,count=0,m,n;
    cin>>m>>n;
    char arr1[m],arr2[n];
    for(i=0;i<m;i++)
            cin>>arr1[i];
            
        for(i=0;i<n;i++)
            cin>>arr2[i];   

    
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr2[j]==arr1[i])
                {
                        for(k=j+1;k<m;k++)
                        {
                            for(l=i+1;l<m;l++)
                            {
                                if((arr1[l]!='0')&&arr2[k]==arr1[l])
                                   {count++;    arr1[l]='0';  
                            }
                        }
                }
        }
    }
    }
    cout<<count+2<<endl;
    
}
    return 0;
}
