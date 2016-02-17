#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;


const int mod = 5000000;

int n, k, a[10005], dp[10005][10005];

int solve(int pos, int len)
{
    if(len == 1 || pos < 0) return 1;
    if(dp[pos][len] != -1) return dp[pos][len];

    dp[pos][len] = 0;
    for(int i = 0; i < pos; i++)
    {
        dp[pos][len] = (dp[pos][len]+(a[i] < a[pos] ? solve(i, len-1) : 0))%mod;
    }

    return dp[pos][len];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    cout<<solve(n-1, k)<<endl;
    return 0;
}
