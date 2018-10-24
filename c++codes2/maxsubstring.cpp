#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int x;
    cin>>x;
    
    while(x--)
    {
        long long k,i,small_alph[125],big_alph[100],max_element_small,max_element_big;
        //string s;
        long long size;
        cin>>size>>k;
        char arr[size];
        for(i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<125;i++)
        {
            small_alph[i]=0;
        }
        for(i=0;i<100;i++)
        {
            big_alph[i]=0;
        }
        for(i=0;i<size;i++)
        {
                small_alph[(int)arr[i]]++;
        }
        for(i=0;i<size;i++)
        {
                big_alph[(int)arr[i]]++;
        }
        
//        for(i=97;i<123;i++)
//        {
//            cout<<"small_alph["<<i<<"]="<<small_alph[i]<<endl;
//        }
//        for(i=65;i<91;i++)
//        {
//            cout<<"big_alph["<<i<<"]="<<big_alph[i]<<endl;
//        }
       max_element_small=*std::max_element(small_alph+97,small_alph+123);
       max_element_big=*std::max_element(big_alph+65,big_alph+91);
       
//       cout<<"m_e_s="<<max_element_small<<endl;
//       cout<<"m_e_b="<<max_element_big<<endl;
//         
           if(max_element_small>=max_element_big)
           {
                if(max_element_small+k>=size)
                     cout<<size<<endl;
                else
                     cout<<max_element_small+k<<endl;     
           }
           else
           {
                    if(max_element_big+k>=size)
                     cout<<size<<endl;
                else
                     cout<<max_element_big+k<<endl;
           }
           
                    
         
       // std::cout << "The largest element is "  << max_element << endl;
        
    }

    return 0;
    
}
