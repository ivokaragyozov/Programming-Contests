#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

int T, dp[2005][2005];
string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;

    for(int cs = 0; cs < T; cs++)
    {
        memset(dp, 0, sizeof(dp));

        cin>>s>>t;
        s = ' '+s;
        t = ' '+t;

        int len1 = s.size(), len2 = t.size();

        for(int i = 0; i < len1; i++)
        {
            dp[i][0] = i;
        }
        for(int i = 0; i < len2; i++)
        {
            dp[0][i] = i;
        }

        for(int i = 1; i < len1; i++)
        {
            for(int j = 1; j < len2; j++)
            {
                if(s[i] == t[j]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
            }
        }

        cout<<dp[len1-1][len2-1]<<endl;
    }

    return 0;
}
