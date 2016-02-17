#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1005, maxK = 1005;

int t, n, k, a[maxN], dp[maxN][maxK];

int solve(int ind, int weight)
{
    if(ind < 0) return 0;
    if(dp[ind][weight] != -1) return dp[ind][weight];

    int ans = 0;
    if(weight - a[ind] >= 0)
    {
        ans = max(solve(ind - 1, weight), solve(ind - 2, weight - a[ind]) + a[ind]);
    }
    else
    {
        ans = solve(ind - 1, weight);
    }

    dp[ind][weight] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 1; cs <= t; cs++)
    {
        cin>>n>>k;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        memset(dp, -1, sizeof(dp));

        cout<<"Scenario #"<<cs<<": "<<solve(n - 1, k)<<endl;
    }

    return 0;
}
