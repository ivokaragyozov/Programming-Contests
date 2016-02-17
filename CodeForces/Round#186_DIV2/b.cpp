#include <iostream>
#define endl '\n'
using namespace std;

string s;
int m, l, r, dp[100005];

void initDP()
{
    int len = s.size(), cur = 0;

    for(int i = 1; i < len; i++)
    {
        if(s[i] == s[i-1]) dp[i-1] = ++cur;
        else dp[i-1] = cur;

        //cout<<dp[i-1]<<" "<<i-1<<endl;
    }
    dp[len-1] = cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>m;

    initDP();

    for(int i = 0; i < m; i++)
    {
        cin>>l>>r;

        cout<<dp[r-2]-dp[l-1]+(((l-1 == 0 && dp[0] == 1) || dp[l-1] != dp[l-2]) ? 1 : 0)<<endl;
    }
    return 0;
}
