#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 1e6;

int n, a[maxN + 5], dp[maxN + 5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	dp[0] = a[0];
	dp[1] = max(dp[0], a[1]);
	dp[2] = max(dp[1], a[2]);

	for(int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 1], max(dp[i - 2], dp[i - 3] + a[i]));
	}

	cout<<dp[n - 1]<<endl;
	return 0;
}
