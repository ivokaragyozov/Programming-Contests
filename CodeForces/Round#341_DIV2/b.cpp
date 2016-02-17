#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool table[1005][1005];
int n, x, y, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>x>>y;

		for(int k = x, p = y; k <= 1000 && p <= 1000; k++, p++)
		{
			if(table[k][p]) ans++;
		}
		for(int k = x, p = y; k >= 1 && p >= 1; k--, p--)
		{
			if(table[k][p]) ans++;
		}
		for(int k = x, p = y; k <= 1000 && p >= 1; k++, p--)
		{
			if(table[k][p]) ans++;
		}
		for(int k = x, p = y; k >= 1 && p <= 1000; k--, p++)
		{
			if(table[k][p]) ans++;
		}

		table[x][y] = true;
	}

	cout<<ans<<endl;
	return 0;
}
