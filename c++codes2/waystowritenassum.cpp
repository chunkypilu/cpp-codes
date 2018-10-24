#include<bits/stdc++.h>
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CASES int t;cin>>t;while(t--)

using namespace std;
 
 
int countWays(int n)
{
    // table[i] will be storing the number of
    // solutions for value i. We need n+1 rows
    // as the table is consturcted in bottom up
    // manner using the base case (n = 0)
    int table[n+1];
 
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
 
    // Base case (If given value is 0)
    table[0] = 1;
 
    // Pick all integer one by one and update the
    // table[] values after the index greater
    // than or equal to n
    for (int i=1; i<n; i++)
        for (int j=i; j<=n; j++)
            table[j] = (table[j]%mod + table[j-i]%mod)%mod;
 
    return table[n]%mod;
}
 
// Driver program
int main()
{
    fast
    CASES
    {
        int n;
        cin>>n;
        cout<<countWays(n)<<"\n";
    }
    return 0;
}
