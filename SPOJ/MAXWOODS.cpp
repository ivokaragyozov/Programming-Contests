#include <bits/stdc++.h>
using namespace std;

const int maxN = 205, maxM = 205;

char board[maxN][maxM];
int t, n, m, dp[maxN][maxM][2];

int solve(int i, int j, int dir)
{
	if(dp[i][j][dir] != -1) return dp[i][j][dir];

	if(dir == 1)
	{
		int val1 = -1, val2 = -1;
		if(i != n - 1 && board[i + 1][j] != '#') val1 = solve(i + 1, j, 0);
		if(j != m - 1 && board[i][j + 1] != '#') val2 = solve(i, j + 1, 1);

		if(max(val1, val2) < 0) return (board[i][j] == 'T' ? 1 : 0);
		
		dp[i][j][dir] = max(val1, val2) + (board[i][j] == 'T' ? 1 : 0);
		return dp[i][j][dir];
	}
	else
	{
		int val1 = -1, val2 = -1;
		if(i != n - 1 && board[i + 1][j] != '#') val1 = solve(i + 1, j, 1);
		if(j != 0 && board[i][j - 1] != '#') val2 = solve(i, j - 1, 0);

		if(max(val1, val2) < 0) return (board[i][j] == 'T' ? 1 : 0);
		
		dp[i][j][dir] = max(val1, val2) + (board[i][j] == 'T' ? 1 : 0);
		return dp[i][j][dir];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	for(int cs = 1; cs <= t; cs++)
	{
		cin>>n>>m;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin>>board[i][j];
			}
		}

		if(board[0][0] == '#')
		{
			cout<<0<<endl;
			continue;
		}
		
		memset(dp, -1, sizeof(dp));
		cout<<solve(0, 0, 1)<<endl;
	}

	return 0;
}
