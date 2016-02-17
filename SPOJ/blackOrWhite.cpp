#include <iostream>
#include <climits>
#include <cstring>
#define endl '\n'
using namespace std;

const int maxN = 200;

int n, a[maxN + 5], dp[maxN + 5][maxN + 5][maxN + 5];

int solve(int currPos, int lastDesc, int lastAsc)
{
	if(currPos == n) return 0;
	if(dp[currPos][lastDesc][lastAsc] != -1) return dp[currPos][lastDesc][lastAsc];

	int ans = 1 + solve(currPos + 1, lastDesc, lastAsc);
	if(a[currPos] > a[lastAsc]) ans = min(ans, solve(currPos + 1, lastDesc, currPos));
	if(a[currPos] < a[lastDesc]) ans = min(ans, solve(currPos + 1, currPos, lastAsc));

	dp[currPos][lastDesc][lastAsc] = ans;
	return ans;
}
void init()
{
	memset(dp, -1, sizeof(dp));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(1)
	{
		cin>>n;
		init();
		if(n == -1) break;

		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
		a[n] = INT_MAX;
		a[n + 1] = -INT_MAX;

		cout<<solve(0, n, n + 1)<<endl;;
	}
	return 0;
}
