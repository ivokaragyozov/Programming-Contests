#include <iostream>
#define endl '\n'
using namespace std;

const int mod = 1e9+7;

int n, k, d;
long long dp[105][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k>>d;
    dp[0][0] = 1;
    dp[0][1] = 0;

    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = 0;

        for(int j = 1; j <= k && i-j >= 0; j++)
        {
            if(j >= d)
            {
                dp[i][1] += dp[i-j][0];
                dp[i][1] += dp[i-j][1];
            }
            else
            {
                dp[i][0] += dp[i-j][0];
                dp[i][1] += dp[i-j][1];
            }

            dp[i][0] %= mod;
            dp[i][1] %= mod;
        }
    }

    cout<<dp[n][1]<<endl;
    return 0;
}
