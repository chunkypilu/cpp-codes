#include <bits/stdc++.h>

using namespace std;



int main()
{
    freopen("8.in","r",stdin);
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector< vector<int> > puzzle(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        //puzzle[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> puzzle[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Write Your Code Here
    
    for (int i = 0; i < n; i++) {
        //puzzle[i].resize(n);

        for (int j = 0; j < n; j++) {
            cout << puzzle[i][j]<<" ";
        }
        cout<<endl;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}

