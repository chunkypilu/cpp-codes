#include<iostream>
#include<cstring>
#include<cstdlib>
 using  namespace std;
 int main()
 {
    int i,j;
    char str[]="\nC++ is better than C";
    int len=strlen(str);
    char *substr=new char[len];
    cout<<"The main string is: "<<str;
    cout<<"Enter substring to be searched: ";
    cin>>substr;
    
    int k,len2=strlen(substr);
    for(i=0;i<len;i++)
    {
        k=i;
        for(j=0;j<len2;j++)
        {
            if(str[k]==substr[j])
            {
                if(j==len2-1)
                {
                    cout<<"\nThe substring is present in main string";
                    exit (EXIT_FAILURE);
                }
                k++;
                
            }
            else
                break;
                
        }
    }
    
    if(i==len)
    {
        cout<<"\n The substring is not present in main string";
        
    }
    
    return 0;
 }
 
