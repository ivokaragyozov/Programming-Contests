#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 35;

int n, home_shirt[maxN], guest_shirt[maxN], ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>home_shirt[i]>>guest_shirt[i];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(home_shirt[i] == guest_shirt[j]) ans++;
			if(home_shirt[j] == guest_shirt[i]) ans++;
		}
	}

	cout<<ans<<endl;
	return 0;
}
