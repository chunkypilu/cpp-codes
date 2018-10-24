#include<iostream>
#include<cstring>
using namespace std;

class person
{
    char name[20];
    float age;
   public:
    person(const char* s,float a)
    {
        strcpy(name,s);
        age=a;
        
    } 
    person& greater(person& x)
    {
        if(x.age>=age)
            return x;
        else
            return *this;    
    }
    
    void display(void)
    {
        cout<<"Name: "<<name<<"\n"
        <<"Age: "<<age<<"\n";
        
    }
 };
 
 int main()
 {
    person  P1("John",37.50),
            P2("Ahmed",29.0),
            P3("Hebber",40.25);
            
           person P=P1.greater(P3);
           cout<<"Elder person is: \n";
           P.display();
           
           P=P1.greater(P2);
           cout<<"Elder person is: \n";
           
           return 0;
 }
