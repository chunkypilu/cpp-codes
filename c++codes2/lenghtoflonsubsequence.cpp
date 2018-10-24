#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int x;
    cin>>x;
    while(x--)
    {
        int m,n,i,j;
        cin>>m>>n;
        char arr1[m],arr2[n];
        int arr3[m][n];
        for(i=0;i<m;i++)
            cin>>arr1[i];
            
        for(i=0;i<n;i++)
            cin>>arr2[i];   
         
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
//                if(arr1[i]==arr2[j])
                    arr3[i][j]=1;
                    cout<<arr3[i][j]<<" ";
            }
        } 
            cout<<endl<<endl;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr1[i]==arr2[j])
                     arr3[i][j]=0;
                     
                    cout<<arr3[i][j]<<" ";
            }
        }     
        
        int no_zeros=0;
        vector<int> v;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr3[j][i]==0)
                  {  no_zeros++;
                        v.push_back(j*10+i);
                   
                  }  
            }
        }
         cout<<endl<<endl;
         
        int max=0,count=0;
        for(i=0;i<v.size();i++)
        {   //count=0;
            cout <<v[i]<<" ";
            if((v[i+1]%10==v[i]%10+1)&&((v[i+1]/10)>(v[i]/10)))
            {
                    count++;
                    cout<<"count="<<count<<endl;
//                    if((v[i+1]/10)==m-1)
//                       {
//                                if(count>max)
//                                        {max =count;
//                                         count=0;              
//                                        }
//                         
//                       }
                        
            }
            
            //max =count;
            if(count>max)
                 max=count;
             if((v[i+1]%10==v[i]%10+1)&&((v[i+1]/10)<(v[i]/10)))
                {max=count;
                       count=0;
                }            
            
        }
        cout<<"i= "<<i<<endl;
       cout<<"count +1="<<max+1<<endl;
        
        
        
        
        
       // cout<<no_zeros;
        
    }
    return 0;
}

/*

Wrong Answer!!!Wrong Answer

The first test case where your code failed:

Input:
584 287
lrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmcoqhnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcacehchzvfrkmlnozjkpqpxrjxkitzyxacbhhkicqcoendtomfgdwdwfcgpxiqvkuytdlcgdewhtaciohordtqkvwcsgspqoqmsboaguwnnyqxnzlgdgwpbtrwblnsadeuguumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayulyeimuotehzriicfskpggkbbipzzrzucxamludfykgruowzgiooobppleqlwphapjnadqhdcnvwdtxjbmyppphauxnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxztqrs vbspkyhsenbppkqtpddbuotbbqcwivrfxjujjddntgeiqvdgaijvwcyaubwewpjvygehljxepbpiwuqzdzubdubzvafspqpqwuzifwovyddwyvvburczmgyjgfdxvtnunneslsplwuiupfxlzbknhkwppanltcfirjcddsozoyvegurfwcsfmoxeqmrjowrghwlkobmeahkgccnaehhsveymqpxhlrnunyfdzrhbasjeuygafoubutpnimuwfjqsjxvkqdorxxvrwctdsneogvbpkxlpgdi

Its Correct output is:
34

And Your Output is:
1

*/
