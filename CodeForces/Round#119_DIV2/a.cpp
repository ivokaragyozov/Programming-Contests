#include <iostream>
#define endl '\n'
using namespace std;

int n, a, b, c, dp[4005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>a>>b>>c;

    dp[a] = 1;
    dp[b] = 1;
    dp[c] = 1;

    for(int i = 1; i <= n; i++)
    {
        if(dp[i])
        {
            if(i+a <= n) dp[i+a] = max(dp[i]+1, dp[i+a]);
            if(i+b <= n) dp[i+b] = max(dp[i]+1, dp[i+b]);
            if(i+c <= n) dp[i+c] = max(dp[i]+1, dp[i+c]);
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}
