#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n, curr, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	curr = 2;
	for(int i = 1; i <= n; i++)
	{
		ans += curr;
		curr *= 2;
	}

	cout<<ans<<endl;
	return 0;
}
