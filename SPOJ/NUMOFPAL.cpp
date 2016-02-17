#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxSize = 1005;

int dp[maxSize][maxSize], ans;
string s;

bool solve(int le, int ri)
{
    if(le >= ri) return true;
    if(dp[le][ri] != -1) return dp[le][ri];

    bool currAns;
    if(s[le] == s[ri]) currAns = solve(le + 1, ri - 1);
    else currAns = false;

    //cout<<le<<" "<<ri<<" "<<currAns<<endl;
    dp[le][ri] = currAns;
    return currAns;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = i; j < s.size(); j++)
        {
            if(solve(i, j)) ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}
