#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 10005;

long long n, a[maxN], b[maxN], dp[maxN][maxN / 2][2];

long long solve(long long indPilot, long long diff, long long c)
{
	if(indPilot == n && diff == 0) return 0;
	else if(indPilot == n) return INT_MAX;
	else if(dp[indPilot][diff][c] != -1) return dp[indPilot][diff][c];

	long long val1, val2;
	if(c == 0) 
	{
		if(diff <= 1) val1 = solve(indPilot + 1, diff - 1, 1) + a[indPilot];
		else val1 = solve(indPilot + 1, diff - 1, 0);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i]>>b[i];
	}
	
	memset(dp, -1, sizeof(dp));
	cout<<solve(0, 0)<<endl;
}
