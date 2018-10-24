#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t,n,k,i,j;
    cin>>t;
    while(t--)
    {
    
      cin>>n;
      int a[n],b[n];
      
        for(i=0;i<n;i++)
            {
            cin>>a[i];
            //cout<<a[i]<<" ";
            b[i]=a[i];
            
            }
        
        //cout<<endl;
        
        cin>>k;
        int sum=0;
        sort(b,b+n,greater<int>());
        
        for(i=0;i<n;i++)
            {
            
            //cout<<b[i]<<" ";
            
            
            }
        
        //cout<<endl;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if((b[i]==a[j])&&(a[j]!=-1))
                {
                    sum+=b[i];
                    a[j]=a[j-1]=a[j+1]=-1;
                    k--;
                    if(k==0)
                      break;
                    
                }
            }
        }
            
    cout<<sum<<endl;
    
    }
    return 0;
    
}
