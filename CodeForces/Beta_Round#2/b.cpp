#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 1000;

int n, a, cnt[maxN + 5][maxN + 5][2], dp[maxN + 5][maxN + 5][2];
char moves[maxN + 5][maxN + 5][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>a;
            while(a % 2 == 0)
            {
                a /= 2;
                cnt[i][j][0]++;
            }

            while(a % 5 == 0)
            {
                a /= 5;
                cnt[i][j][1]++;
            }
        }
    }

    dp[0][0][0] = cnt[0][0][0];
    dp[0][0][1] = cnt[0][0][1];
    for(int i = 1; i < n; i++)
    {
        dp[0][i][0] = dp[0][i - 1][0] + cnt[0][i][0];
        dp[i][0][0] = dp[i - 1][0][0] + cnt[i][0][0];
        dp[0][i][1] = dp[0][i - 1][1] + cnt[0][i][1];
        dp[i][0][1] = dp[i - 1][0][1] + cnt[i][0][1];

        moves[0][i][0] = 'R';
        moves[0][i][1] = 'R';
        moves[i][0][0] = 'D';
        moves[i][0][1] = 'D';
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(dp[i - 1][j][0] < dp[i][j - 1][0])
            {
                moves[i][j][0] = 'D';
                dp[i][j][0] = dp[i - 1][j][0] + cnt[i][j][0];
            }
            else
            {
                moves[i][j][0] = 'R';
                dp[i][j][0] = dp[i][j - 1][0] + cnt[i][j][0];
            }

            if(dp[i - 1][j][1] < dp[i][j - 1][1])
            {
                moves[i][j][1] = 'D';
                dp[i][j][1] = dp[i - 1][j][1] + cnt[i][j][1];
            }
            else
            {
                moves[i][j][1] = 'R';
                dp[i][j][1] = dp[i][j - 1][1] + cnt[i][j][1];
            }
        }
    }

    if(dp[n - 1][n - 1][0] <= dp[n - 1][n - 1][1])
    {
        cout<<dp[n - 1][n - 1][0]<<endl;

        int i = n - 1, j = n - 1;
        string path;
        while(1)
        {
            if(moves[i][j][0] == 'D')
            {
                path += 'D';
                i--;
            }
            else
            {
                path += 'R';
                j--;
            }


            if(i == 0 && j == 0) break;
        }

        reverse(path.begin(), path.end());
        cout<<path<<endl;
    }
    else
    {
        cout<<dp[n - 1][n - 1][1]<<endl;

        int i = n - 1, j = n - 1;
        string path;
        while(1)
        {
            if(moves[i][j][1] == 'D')
            {
                path += 'D';
                i--;
            }
            else
            {
                path += 'R';
                j--;
            }

            if(i == 0 && j == 0) break;
        }

        reverse(path.begin(), path.end());
        cout<<path<<endl;
    }

    return 0;
}
