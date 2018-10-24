#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    fstream fs("test.txt");
    
    cout << fs.is_open() << endl; 
    
    return 0;
}

