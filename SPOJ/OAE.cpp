#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 5, mod = 314159;

long long t, n, dp[maxN][2];

long long solve(int ind, int c)
{
	if(ind == n && c == 0) return 1;
	else if(ind == n) return 0;
	if(dp[ind][c] != -1) return dp[ind][c];
	
	long long currAns = 0;
	if(c == 0) currAns = (9 * solve(ind + 1, 0) + solve(ind + 1, 1)) % mod;
	else currAns = (9 * solve(ind + 1, 1) + solve(ind + 1, 0)) % mod;

	dp[ind][c] = currAns;
	return currAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;
	for(int cs = 1; cs <= t; cs++)
	{
		cin>>n;

		memset(dp, -1, sizeof(dp));
		cout<<solve(0, 0)<<endl;
	}
}
