#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int maxN = 1e4;

int n1, n2, arr[maxN + 5][2], pos[2 * maxN + 5][2], dp[2][maxN + 5];

int solve(int a, int ind)
{
    if(ind == -1) return 0;
    if(dp[a][ind] != -1) return dp[a][ind];

    int ans = 0;
    ans += solve(a, ind - 1);
    if(a == 0)
    {
        if(pos[arr[ind][0] + maxN][1] != -1) ans = max(solve(1, pos[arr[ind][0] + maxN][1] - 1), ans);
    }
    else
    {
        if(pos[arr[ind][1] + maxN][0] != -1) ans = max(solve(0, pos[arr[ind][1] + maxN][0] - 1), ans);
    }

    ans += arr[ind][a];

    dp[a][ind] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        memset(pos, -1, sizeof(pos));

        cin>>n1;
        if(n1 == 0) break;

        for(int i = 0; i < n1; i++)
        {
            cin>>arr[i][0];
            pos[arr[i][0] + maxN][0] = i;
        }
        cin>>n2;
        for(int i = 0; i < n2; i++)
        {
            cin>>arr[i][1];
            pos[arr[i][1] + maxN][1] = i;
        }

        memset(dp, -1, sizeof(dp));
        cout<<max(solve(0, n1 - 1), solve(1, n2 - 1))<<endl;
    }

    return 0;
}
