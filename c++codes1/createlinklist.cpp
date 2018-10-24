#include<iostream>
using namespace std;


int main()
{

typedef struct _NODE
 {
    int data;
    _NODE *ptr;
 } NODE;


    _NODE *head,n1;
    n1.data=5;
  //  head=n1;
    cout<<n1.data;
    return 0;
}
