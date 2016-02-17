#include <iostream>
#define endl '\n'
using namespace std;

int t, n, m, dp[105][105], a, curMax;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        curMax = 0;

        cin>>n>>m;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin>>a;

                if(i == 0) dp[i][j] = a;
                else
                {
                    dp[i][j] = dp[i-1][j];

                    if(j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                    if(j+1 < m) dp[i][j] = max(dp[i][j], dp[i-1][j+1]);

                    dp[i][j] += a;
                }

                if(dp[i][j] > curMax) curMax = dp[i][j];
            }
        }

        cout<<curMax<<endl;
    }

    return 0;
}
