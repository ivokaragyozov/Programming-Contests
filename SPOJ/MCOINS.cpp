#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 5;

int k, l, m, n, dp[maxN];

bool solve(int a)
{
    if(a == 0) return false;
    if(a < 0) return true;
    if(dp[a] != -1) return dp[a];

    if(!solve(a - 1) || !solve(a - k) || !solve(a - l)) return dp[a] = true;
    else return dp[a] = false;

    return dp[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k>>l>>m;

    dp[0] = false;
    for(int i = 1; i < maxN; i++)
    {
        if((i - 1 >= 0 && !dp[i - 1]) || (i - k >= 0 && !dp[i - k]) || (i - l >= 0 && !dp[i - l])) dp[i] = true;
        else dp[i] = false;
    }

    for(int i = 0; i < m; i++)
    {
        cin>>n;
        cout<<(dp[n] ? 'A' : 'B');
    }
    cout<<endl;

    return 0;
}
