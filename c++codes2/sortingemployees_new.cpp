#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


class emp
{

public:
    string name;
    int sal;
};

bool acc_name(emp e1,emp e2)
{
    if(e1.sal!=e2.sal)
    return e1.sal<e2.sal;
    return e1.name<e2.name;
}


int main()
{
    int t,no_emp,i,j,k,x;
    string y;
    cin>>t;
    while(t--)
    {
        cin>>no_emp;
        emp e[no_emp],e_obj;
        for(i=0;i<no_emp;i++)
        {
            cin>>e[i].name;
            cin>>e[i].sal;
        }
        
    /*    for(i=0;i<no_emp;i++)
        {
            cout<<e[i].name<<" ";
            cout<<e[i].sal;
            cout<<endl;
        }
      */ 
      /*sorting salaries*/
    /*  for(i=0;i<no_emp;i++)
      {
      
        cin>>e[i].name;
        cin>>e[i].sal;
            
        for(j=0;j<i;j++)
        {
            if(e[i].sal<e[j].sal)
            {
                //x=e[i].sal;  y=e[i].name;
                e_obj=e[i];
                for(k=i;k>=j+1;k--)
                {
                    //e[k].sal=e[k-1].sal;
                    //e[k].name=e[k-1].name;
                    e[k]=e[k-1];
                    
                }
                //e[j].sal=x;
                //e[j].name=y;
                e[j]=e_obj;
            }
            if(e[i].sal==e[j].sal)
            {
                //x=e[i].sal;  y=e[i].name;
                e_obj=e[i];
                for(k=i;k>=j+2;k--)
                {
                    //e[k].sal=e[k-1].sal;
                    //e[k].name=e[k-1].name;
                    e[k]=e[k-1];
                    
                }
                if(e[i].name[0]<e[j].name[0])
                {
                    //e[j+1].name=e[j].name;
                    //e[j+1].sal=e[j].sal;
                    e[j+1]=e[j];
                    
                    //e[j].name=y;
                    //e[j].sal=x;
                    e[j]=e_obj;
                    
                }
                else
                {
                    //e[j+1].sal=x;
                    //e[j+1].name=y;
                    e[j+1]=e_obj;
                }
                                
            }
        }
      }
       */
       
       /*   sort using sort function   */
       

       sort(e,e+no_emp,acc_name);
       
       
       
       
            for(i=0;i<no_emp;i++)
        {
            cout<<e[i].name<<" ";
            cout<<e[i].sal<<" ";
            
        }
        cout<<endl;
       
    
    }
    
    
    return 0;
    
}
