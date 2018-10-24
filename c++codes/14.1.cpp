#include<iostream>
#include<vector>
using namespace std;

void display(vector<int > &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    vector<int > v;
    cout<<"Initial size= "<<v.size()<<"\n";
    
    int x;
    cout<<"Enter five integer values: ";
    for(int i=0;i<5;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cout<<"size after adding five values:";
    cout<<v.size()<<"\n";
    
    cout<<"current contents:\n";
    display(v);
    
    v.push_back(6.6);
    
    cout<<"\nsize="<<v.size()<<"\n";
    cout<<"contents now : \n";
    display(v);
    
    vector<int> ::iterator itr=v.begin();
    itr=itr+3;
    v.insert(itr,1,9);
    
    
    cout<<"\ncontents after insertion: \n";
    display(v);
    
    
    v.erase(v.begin()+3,v.begin()+5);
    
    
    cout<<"contents after deletion: \n";
    display(v);
    cout<<"END\n";
    
    return 0;
    
}
