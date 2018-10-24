#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,i;
        cin>>n;
        int arr[n],index_arr[n],max,sum=0,k,j,index,max_elem_index,max_elem;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            index_arr[i]=n+10;
            //cout<<"index_arr="<<index_arr[i]<<" ";
            
        }
        
        for(k=0;k<n;k++)
        {
        
        max_elem_index=max_element(arr, arr + n)-arr;
        max_elem=*max_element(arr, arr + n);
        arr[max_elem_index]=0;  arr[max_elem_index+1]=0;  arr[max_elem_index-1]=0;
       // cout<<"indent max_elem= "<<max_elem_index<<" "<<max_elem<<endl;
        sum+=max_elem;
        
        
        
//            max=arr[0];index=0;
//                for(i=1;i<n;i++)
//                {
//                    if(arr[i]>max)
//                    {
//                            max=arr[i];
//                            index=i;
//                               
//                    }
//                     
//                }
//                
//                arr[index]=0;    
//                //cout<<"max index"<<max<<" "<<index<<endl;
//                
//                
//                for(j=0;j<n;j++)
//                {
//                    if((index_arr[j]==(index+1))||(index_arr[j]==(index-1)))
//                    {
//                        break;
//                    }
//                }
//                
//               // cout<<"j="<<j<<" ";
//                
//                if(j==n)
//                {
//                    index_arr[k]=index;    
//                    sum+=max;
//                }
//                //cout<<"index_arr= "<<k<<" "<<index_arr[k]<<endl;
      }
//       
  //       cout<<sum<<endl;  
//        
        cout<<sum<<endl;
        
        }
    return 0;
}
