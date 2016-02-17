/**
Ivo Karagyozov
Zimni 2015 C3 rod
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 505;

int n, a[maxN], dp[maxN][maxN], sums[maxN];

int solve(int le, int ri)
{
    if(le == ri) return 0;
    if(dp[le][ri] != -1) return dp[le][ri];

    int ans = INT_MAX;
    for(int i = le; i < ri; i++)
    {
        ans = min(ans, solve(le, i) + solve(i + 1, ri));
    }

    ans += sums[ri] - sums[le - 1];

    dp[le][ri] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(i != 1) sums[i] = sums[i - 1];
        sums[i] += a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout<<solve(1, n)<<endl;
    return 0;
}
