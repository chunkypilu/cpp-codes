#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main()
{
    int x;
    cin>>x;
    while(x--)
    {   
        int size;
        vector<string> v;
        cin>>size;
        string s;
        
        while(size--)
        {
            cin>>s;
            v.push_back(s);
            
        }
//        vector<string>::iterator it;
//        for(it=v.begin() ; it < v.end(); it++)
//            {
//                cout<<*it<<" ";
//            }       
        
        map<int,string> m; int i,j,count;
        string k;
        for(i=0;(i<v.size());i++)
        {
             if(v[i]!="00")
             {
            count=0;k=v[i];
            
            //cout<<"k="<<k<<endl;
            for(j=0;j<v.size();j++)
            {
                if((v[j]==k)&&(v[j]!="00"))
                {
                    count++; v[j]="00";
                }
            }
            
           m[count]=k;
           }
        }
        
        map<int,string >:: iterator it1;
       // for(it1=m.begin();it1!=m.end();it1++)
       // {
        //    cout<<(*it1).first<<" "<<(*it1).second<<endl;
       // }
        
        it1=m.end();
        //it1=it1-2;
        it1--;
        it1--;
        cout<<(*(it1--)).second<<endl;
       

    }


    return 0;
}
