#include <iostream>
#include <climits>
#include <cstring>
#define endl '\n'
using namespace std;

int n, m, a[205], dp[205][205];

int solve(int currInd, int currGroup)
{
    if(currGroup == 0) return 0;

    if(dp[currInd][currGroup] != -1) return dp[currInd][currGroup];

    int val1 = INT_MAX;
    for(int i = currInd-1; i >= 0; i--)
    {
        val1 = min(dp[i][curr])
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin>>n>>m;

    for(int i = 0; i <= m; i++)
    {
        cin>>a[i];
    }

    solve(m-1, n);
}
