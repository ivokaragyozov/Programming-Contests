#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int maxN = 505, maxM = 505, maxB = 205;

int n, m, b, mod, dp[maxN][maxM][maxB], a[maxN];

int solve(int programmer, int bugs, int lines)
{
    if(bugs > b) return 0;
    if(lines == m) return 1;
    if(programmer < 0) return 0;
    if(dp[programmer][bugs][lines] != -1) return dp[programmer][bugs][lines];

    int ans = 0;
    for(int i = 0; i <= m - lines; i++)
    {
        ans = (ans + solve(programmer - 1, bugs + a[programmer] * i, lines + i)) % mod;
    }

    dp[programmer][bugs][lines] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>b>>mod;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout<<solve(n - 1, 0, 0)<<endl;
    return 0;
}
