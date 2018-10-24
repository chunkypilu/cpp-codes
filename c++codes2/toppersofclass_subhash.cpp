#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			b[i]=a[i];
		}
		int k;
		cin >> k;
		
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		reverse(a.begin(), a.end());
		for(int i=0;i<a.size() && i<k;i++)
		{
//			cout << a[i] << " ";
//			f=0;
			
			for(int j=0;j<b.size();j++)
			{
				if(b[j]==a[i])
				{
					cout << j << " ";
				}
			}
//			cout << endl;
		}
		cout << endl;
	}
	
return 0;
}


/*
input:
1
5
2 2 1 3 1
2

output:
3 0 1 
*/
