#include <iostream>
#define endl '\n'
using namespace std;

int k, l, m, n[55], dp[1000005][2], maxN;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k>>l>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>n[i];

        if(n[i] > maxN) maxN = n[i];
    }

    dp[0][0] = -1;
    dp[0][1] = -1;
    for(int i = 1; i <= maxN; i++)
    {
        if(dp[i-1][1] == -1 || (i-k >= 0 && dp[i-k][1] == -1) || (i-l >= 0 && dp[i-l][1] == -1)) dp[i][0] = 1;
        else dp[i][0] = -1;

        if(dp[i-1][0] == -1 || (i-k >= 0 && dp[i-k][0] == -1) || (i-l >= 0 && dp[i-l][0] == -1)) dp[i][1] = 1;
        else dp[i][1] = -1;
    }

    for(int i = 0; i < m; i++)
    {
        cout<<(dp[n[i]][0] == -1 ? 'B' : 'A');
    }

    cout<<endl;
    return 0;
}
