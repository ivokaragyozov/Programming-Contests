#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxLen = 1e3 + 5;

int k, dp[maxLen][maxLen];
string s, t;

int solve(int ind1, int ind2)
{
    if(ind1 == -1 || ind2 == -1) return 0;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    int curr = 0;
    while((ind1 - curr != -1 || ind2 - curr != -1) && s[ind1 - curr] == t[ind2 - curr])
    {
        curr++;
    }

    int ans = 0;
    if(curr >= k) ans += solve(ind1 - curr, ind2 - curr) + curr;
    else ans = max(solve(ind1, ind2 - 1), solve(ind1 - 1, ind2));

    dp[ind1][ind2] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        cin>>k;
        if(k == 0) break;

        cin>>s>>t;

        memset(dp, -1, sizeof(dp));
        cout<<solve(s.size() - 1, t.size() - 1)<<endl;
    }

    return 0;
}
