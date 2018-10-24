#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num, arr[10];
    int x, y, a, b;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    cout << "Max element Index: " << *max_element(arr, arr + num);

    return 0;
}
