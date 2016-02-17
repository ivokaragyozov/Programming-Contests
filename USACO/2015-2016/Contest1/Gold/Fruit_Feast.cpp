#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxT = 5e6 + 5;

int a, b, t, dp[maxT][2];

int solve(int curr, int water)
{
    if(curr > t) return 0;
    if(curr <= t && curr + a > t && curr + b > t && water == 1) return curr;
    if(dp[curr][water] != -1) return dp[curr][water];

    int currAns = 0;
    currAns = max(currAns, solve(curr + a, water));
    currAns = max(currAns, solve(curr + b, water));
    if(water == 0) currAns = max(currAns, solve(curr / 2, 1));

    //cout<<curr<<" "<<water<<" "<<currAns<<endl;
    dp[curr][water] = currAns;
    return currAns;
}

int main()
{
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin>>t>>a>>b;
    cout<<solve(0, 0)<<endl;

    return 0;
}
