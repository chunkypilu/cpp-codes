#include<iostream>
#include<map>
//#include<iterator>
#define CASE int t;cin>> t;while(t--)
using namespace std;

int main()
{   

    CASE{
        int n,i,k=0,sum=0,j;  cin>>n;
        int arr[n],index_arr[n];
        multimap<int ,int> arrmap;
        for(i=0;i<n;i++) 
        {
            cin>>arr[i];
            //arrmap[i]=arr[i];
            index_arr[i]=n+10;
            arrmap.insert(std::pair<int,int>(arr[i],i));
        }
       // multimap<int ,int> :: iterator it;
       multimap<int ,int> :: reverse_iterator it = arrmap.rbegin();

        while(it!=arrmap.rend())
        {
           // cout<<(*it).first<<" "<<(*it).second<<endl; 
            
//            for(j=0;j<n;j++)
//            {
//                    if((index_arr[j]==((*it).second+1))||(index_arr[j]==((*it).second-1)))
//                    {
//                        break;
//                    }
//            }
            
//            if(j==n&&k<n)
//                {
//                    index_arr[k]=(*it).second;    
//                    sum+=(*it).first;
//                   // cout<<"index_arr= "<<k<<" "<<index_arr[k]<<endl;
//                    //cout<<"sum="<<sum<<endl;
//                }
                //cout<<"index_arr= "<<k<<" "<<index_arr[k]<<endl;
                
//            k++;          it++;
            }
        cout<<sum<<endl;

    
    }


    return 0;
}
