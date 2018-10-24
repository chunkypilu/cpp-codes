#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int x;
    cin>>x;
    while(x--)
    {
        int n1,n2,n3,i,j,k;
        cin>>n1>>n2>>n3;
        char arr1[n1],arr2[n2],arr3[n3];
        for(i=0;i<n1;i++)
            cin>>arr1[i];
            
        for(i=0;i<n2;i++)
            cin>>arr2[i];

        for(i=0;i<n3;i++)
            cin>>arr3[i];
            
            
         int a[n1],b[n2],c[n3];
        for(i=0;i<n1;i++)
            a[i]=(int)arr1[i];
            
        for(i=0;i<n2;i++)
            b[i]=(int)arr2[i];

        for(i=0;i<n3;i++)
            c[i]=(int)arr3[i];   
            
            
            int count=0,max=0,prev=0;
            for(i=0;i<n1;i++)
               {   count=0; 
                for(j=0;j<n2;j++)
                {
                   
                    if(a[i]==b[j])
                    {
                       count++;
                       
//                       //cout<<"min="<<min(n1,n2)<<endl;
//                       
//                       for(k=i+1;k<min(n1,n2);k++)
//                       {
//                            if(a[k]==b[k])
//                                count++;
//                             //   cout<<"count="<<count<<endl;
//                       }
//                       
                       
                    }
                    if(count>max)
                      {max=count;
                      //cout<<"max="<<count<<endl;
                      }
                    
                    //prev=count;
                    //cout<<"prev="<<prev<<endl;
                }
                
                
               }
        
        cout<<max<<endl;
        
        
    }
    return 0 ;
    
}
