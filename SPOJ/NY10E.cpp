#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 69;

long long t, p, n, dp[maxN][15];

long long solve(int ind, int lastDig)
{
    if(ind == 0) return 1;
    if(dp[ind][lastDig] != -1) return dp[ind][lastDig];

    long long ans = 0;
    for(int i = 0; i <= lastDig; i++)
    {
        ans += solve(ind - 1, i);
    }

    dp[ind][lastDig] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>p>>n;

        cout<<p<<" "<<solve(n, 9)<<endl;
    }

    return 0;
}
