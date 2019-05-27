/*#include<bits/stdc++.h>
using namespace std;

int main()
{

int t=5;
 array<int,4> a;

return 0;
}*/

// array::begin example
#include <iostream>
#include <array>

int main ()
{
  std::array<int,5> myarray = { 2, 16, 77, 34, 50 };

  std::array<int,5> :: iterator it;

  std::cout << "myarray contains:";
  for ( it = myarray.begin(); it != myarray.end(); ++it )
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
