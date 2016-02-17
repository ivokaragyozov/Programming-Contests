#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int maxN = 1e3 * 6;

string s;
int dp[maxN + 5];

int solve(int pos)
{
    if(pos == 0)
    {
        if(s[0] == '0') return 0;
        else return 1;
    }
    if(pos == 1)
    {
        if(s.substr(0, 2) <= "26")
        {
            if(s[0] == '0') return 0;
            else if(s[1] == '0') return 1;
            else return 2;
        }
        else return 1;
    }
    if(dp[pos] != -1) return dp[pos];

    int ans = 0;
    if(s[pos] != '0') ans += solve(pos - 1);
    if(s.substr(pos - 1, 2) <= "26" && s[pos - 1] != '0') ans += solve(pos - 2);

    dp[pos] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        memset(dp, -1, sizeof(dp));

        cin>>s;
        if(s == "0") break;

        cout<<solve(s.size() - 1)<<endl;
    }

    return 0;
}
