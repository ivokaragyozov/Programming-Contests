#include <iostream>
#include <cstring>
#include <cmath>
#define endl '\n'
using namespace std;

const int maxLen = 1e5 + 5, mod = 1e9 + 7;

long long t, k, a, b, dp[maxLen], currAns, sums[maxLen];

int solve(int len)
{
    if(len < 0) return 0;
    if(len <= 1)
    {
        if(k > 1) return 1;
        else return 2;
    }
    if(dp[len] != -1) return dp[len];

    int ans;
    ans = (solve(len - 1) + solve(len - k)) % mod;

    dp[len] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin>>t>>k;

    for(int i = 1; i <= maxLen - 5; i++)
    {
        sums[i] = (sums[i - 1] + solve(i)) % mod;
    }

    for(int cs = 0; cs < t; cs++)
    {
        cin>>a>>b;

        if(a > b) swap(a, b);

        cout<<(sums[b] - sums[a - 1] + mod) % mod<<endl;
    }

    return 0;
}
