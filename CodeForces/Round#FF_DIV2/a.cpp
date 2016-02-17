#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e3;

int n, a[maxN], dp[maxN][maxN];

int solve(int beg, int en)
{
    if(beg == en) return 1;
    if(dp[beg][en] != -1) return dp[beg][en];

    if(a[beg] <= a[en]) ans = solve(beg + 1, en - 1) + 2;
    else
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout<<solve(0, n - 1)<<endl;
}
