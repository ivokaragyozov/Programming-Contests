#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;

int t, dp[6105][6105];
string s, reversedS;

void init()
{
    memset(dp, 0, sizeof(dp));
}
void LCS()
{
    s = " "+s;
    reversedS = " "+reversedS;

    int len = s.size();

    for(int i = 1; i < len; i++)
    {
        for(int j = 1; j < len; j++)
        {
            if(s[i] == reversedS[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;

    for(int cs = 0; cs < t; cs++)
    {
        cin>>s;

        reversedS = s;
        reverse(reversedS.begin(), reversedS.end());

        init();
        LCS();

        cout<<s.size()-1-dp[s.size()-1][s.size()-1]<<endl;
    }

    return 0;
}
