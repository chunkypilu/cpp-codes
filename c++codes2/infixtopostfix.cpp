#include<bits/stdc++.h>
using namespace std;

int priority(char ch)
{
    if(ch=='^')
      return 3;
    if(ch=='*'||ch=='/'||ch=='%')
      return 2;
    if(ch=='+'||ch=='-')
      return 1;
}

void prefixTopostfix(string s)
{
    stack<char> mystack;
    int len=s.length(),i;
    
        mystack.push('0');
    for(i=0;i<len;i++)
    {
        if((s[i]>='a'&&s[i]<='z')||(s[i])>='A'&&s[i]<='Z')
        {
               cout<<s[i];
        }
        else if(s[i]=='(')
        {
            mystack.push(s[i]);
            
        }
        else if(s[i]==')')
        {
                while(mystack.top()!='(')
                {
                    cout<<mystack.top();
                    mystack.pop();
                }
                if(mystack.top()=='(')
                {
                    mystack.pop();
                }
                
        }
        else
        {
           while((priority(mystack.top())>=priority(s[i]))&&(mystack.top()!='0')&&(mystack.top()!='('))
            {
                 cout<<mystack.top();
                 mystack.pop();
            }
              
              mystack.push(s[i]);
        }
    }
    while (!mystack.empty()&&mystack.top()!='0')
  {
    cout << mystack.top();
     mystack.pop();
  }
 
}

int main()
{
    string s="A*(B+C)/D";
    prefixTopostfix(s);
    
}
