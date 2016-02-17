#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxSize = 1005;

int dp[maxSize][maxSize];
string s, t;

void LCS(string a, string b)
{
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= a.size(); i++)
    {
        for(int j = 1; j <= b.size(); j++)
        {
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        cin>>s;
        if(s == "#") break;
        cin>>t;

        LCS(s, t);

        cout<<(s.size() - dp[s.size()][t.size()]) * 15 + (t.size() - dp[s.size()][t.size()]) * 30<<endl;
    }

    return 0;
}
