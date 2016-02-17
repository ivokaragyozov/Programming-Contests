#include <iostream>
#define endl '\n'
using namespace std;

int n, m, x, y, startPower, table[25][25], dp[25][25];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>x>>y;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>>table[i][j];
        }
    }

    startPower = table[x][y];
    dp[x][y] = startPower;

    for(int i = y+1; i <= m; i++)
    {
        dp[x][i] = dp[x][i-1]-table[x][i];
    }
    for(int i = x+1; i <= n; i++)
    {
        dp[i][y] = dp[i-1][y]-table[i][y];
    }
    for(int i = x+1; i <= n; i++)
    {
        for(int j = y+1; j <= m; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])-table[i][j];
        }
    }


    if(dp[n][m] >= 0) cout<<"Y"<<endl<<dp[n][m]<<endl;
    else cout<<"N"<<endl;
    return 0;
}
