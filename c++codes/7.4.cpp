#include<iostream>
#include<cstring>
using namespace std;

class String
{
    char *p;
    int len;
   public:
    String(){len=0;p=0;}
    String(const char *s);
    String(const String &s);
    ~String(){delete p;} 
    
    friend String operator+(const String &s,const String &t);
    friend int operator <=(const String &s,const String &t);
    friend void show(const String s);
};

String::String(const char *s)
{
    len =strlen(s);
    p=new char[len+1];
    strcpy(p,s);
    
}

String ::String(const String & s)
{
    len=s.len;
    p=new char[len+1];
    strcpy(p,s.p);
    
}

String operator+(const String &s,const String &t)
{
    String temp;
    temp.len=s.len+t.len;
    temp.p=new char[temp.len+1];
    strcpy(temp.p,s.p);
    strcat(temp.p,t.p);
    return (temp);
    
    
}


int operator<=(const String &s, const String &t)
{
    int m=strlen(s.p);
    int n= strlen(t.p);
    
    if(m<=n) return(1);
    else return 0;
    
}

void show(const String s)
{
    cout<<s.p;
    
}

int main()
{
    String s1="New ";
    String s2="York";
    String s3="Delhi";
    String String1,String2,String3;
    String1=s1;
    String2=s2;
   // String3=s1+s3;
    
    
    cout<<"\nString1= "; show(String1);
    cout<<"\nString2= "; show(String2);
    cout<<"\n";
    cout<<"\nString3= "; show(s1+s3);
    cout<<"\n\n";
    
    if(String1<=s1+s3)
    {
        show(String1);
        cout<<" smaller than ";
        show(s1+s3);
        cout<<"\n";
    }
    else
    {
        show(String3);
        cout<<"smaller than ";
        show(String1);
        cout<<"\n";
    }
    return 0;
}
