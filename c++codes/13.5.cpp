#include<iostream>
#include<cstring>
//#include<>

using namespace std;
class Error
{
    int err_code;
    char *err_desc;
   public:
    Error(int c, char *d)
    {
        err_code=c;
        err_desc=new char[strlen(d)];
        strcpy(err_desc,d);
        
    } 
    void err_display(void)
    {
        cout<<"Error code:"<<err_code<<"\n"<<"Error description: "<<err_desc;
        
    }
};

int main()
{
    try
    {
        cout<<"Press any key to throw test exception:";
        getch();
        throw Error(99,"Test Exception");
    }
    catch(Error e)
    {
        cout<<"Exception caught sucessfully";
        e.err_display();
        
    }
    getch();
    return 0;
}
