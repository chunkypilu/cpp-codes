#include<iostream>
using namespace std;



int main()
{
    int x,no_elements,value,i,even,odd;
    cin>>x;
    while(x--)
    {   even=0;odd=0;
        cin>>no_elements;
        int arr[no_elements];
        for(i=0;i<no_elements;i++)
          {cin>>arr[i];
          }

        for(i=0;i<no_elements;i++)
        {
            
                if(arr[i]%2==0)
                   even++;
                  else 
                  odd++; 
            
        }
        cout<<even*odd<<endl;      
    }


return 0;
}
