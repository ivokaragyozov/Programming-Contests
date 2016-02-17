#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;


const int mod = 1000000007;

long long t, dp[100005], last[100005];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>s;

        memset(dp, 0, sizeof(dp));
        memset(last, 0, sizeof(last));

        int len = s.size();

        dp[0] = 1;
        for(int i = 1; i <= len; i++)
        {
            dp[i] = (dp[i-1]*2) % mod;
            if(last[s[i-1]-'A'] != 0) dp[i] = (dp[i]-dp[last[s[i-1]-'A']-1]+mod)%mod;
            last[s[i-1]-'A'] = i;
        }

        cout<<dp[len]<<endl;
    }

    return 0;
}
