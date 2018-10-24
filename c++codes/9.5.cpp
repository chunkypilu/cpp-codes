#include<iostream>
#include<cstring>
#include<cwctype>

using namespace std;
int main()
{
    int i=0;
    char const *ptr[10]={"books","television","computer","sports"};
    char str[25];
    cout<<"\nEnter your favourite leisure pursuit: ";
    cin>>str;
    for(i=0;i<4;i++)
        {
            if(!strcmp(str,ptr[i]))
                {
                    cout<<"\navilable";
                    break;
                    
                }
        }
        
        if(i==4)
        {
            cout<<"\n\nNot available";
        }
        return 0;
}
