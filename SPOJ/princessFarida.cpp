#include <iostream>
#define endl '\n'
using namespace std;

long long t, n, a, dp[10005][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 1; cs <= t; cs++)
    {
        cin>>n;

        dp[0][0] = 0;
        dp[0][1] = 0;

        for(int i = 1; i <= n; i++)
        {
            cin>>a;

            if(i >= 2) dp[i][0] = max(dp[i-2][0], dp[i-1][1])+a;
            else dp[i][0] = a;

            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        }

        cout<<"Case "<<cs<<": "<<max(dp[n][0], dp[n][1])<<endl;
    }

    return 0;
}
