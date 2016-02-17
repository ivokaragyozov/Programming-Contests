#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 5 * 1e5 + 5;

int n, l[maxN], r[maxN], maxR;
map<int, vector<int> > en;
map<int, int> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>l[i]>>r[i];

        if(r[i] > maxR) maxR = r[i];

        en[r[i]].push_back(l[i]);
    }

    dp[0] = 0;
    for(int i = 1; i <= maxR; i++)
    {
        if(en.find(i) != en.end())
        {
            for(int j = 0; j < en[i].size(); j++)
            {
                dp[i] = max(dp[en[i][j] - 1] + 1, dp[i]);
            }
        }

        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout<<dp[maxR]<<endl;
    return 0;
}
