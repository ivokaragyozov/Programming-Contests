#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

int n, a[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		a[i] %= 2;
	}

	for(int i = 2; i < n; i++)
	{
		if(a[i] != a[0] || a[i] != a[1] || a[0] != a[1])
		{
			if(a[0] == a[1]) cout<<i + 1<<endl;
			else if(a[0] == a[i]) cout<<2<<endl;
			else cout<<1<<endl;
			return 0;
		}
	}

	return 0;
}
