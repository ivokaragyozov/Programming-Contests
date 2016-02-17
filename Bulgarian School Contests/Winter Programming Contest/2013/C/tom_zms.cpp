#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxM = 1e5 + 5;

long long m, k, a[maxM], b[maxM], ans, curr, k1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>m>>k;
	for(int i = 0; i < m; i++)
	{
		cin>>a[i]>>b[i];
	}

	k1 = k;
	int i = 0;
	curr = a[0];
	ans = a[0];
	while(1)
	{
		cout<<curr<<" "<<k<<" "<<a[i]<<" "<<b[i]<<" "<<ans<<endl;
		if(curr + k <= b[i])
		{
			ans += k - 1;
			curr += k;
			ans += 2 * curr - 1;
			k = k1;
		}
		else
		{
			k -= b[i] - curr + 1;
			ans += b[i] - curr;
			curr = b[i];
			i++;
			if(i == m) break;
			ans += a[i] - curr;
			curr = a[i];
		}
	}
	ans += b[m - 1];

	cout<<ans<<endl;
	return 0;
}
