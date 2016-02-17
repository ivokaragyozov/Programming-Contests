#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 35;

long long t, n, dp[maxN][5][5];

long long solve(int ind, int last1, int last2)
{
    if(ind == 0)
    {
        if(last1 != last2) return 2;
        else return 3;
    }
    if(dp[ind][last1][last2] != -1) return dp[ind][last1][last2];

    dp[ind][last1][last2] = solve(ind - 1, last1, last1);
    if(last1 == last2)
    {
        if(last1 == 0) dp[ind][last1][last2] += solve(ind - 1, 1, 0) + solve(ind - 1, 2, 0);
        else if(last1 == 1) dp[ind][last1][last2] += solve(ind - 1, 0, 1) + solve(ind - 1, 2, 1);
        else dp[ind][last1][last2] += solve(ind - 1, 0, 2) + solve(ind - 1, 1, 2);
    }
    else dp[ind][last1][last2] += solve(ind - 1, last2, last1);

    //cout<<ind<<" "<<last1<<" "<<last2<<" "<<dp[ind][last1][last2]<<endl;
    return dp[ind][last1][last2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    memset(dp, -1, sizeof(dp));
    for(int cs = 0; cs < t; cs++)
    {
        cin>>n;

        if(n == 1) cout<<3<<endl;
        else if(n == 2) cout<<9<<endl;
        else cout<<2 * (solve(n - 3, 0, 1) + solve(n - 3, 1, 2) + solve(n - 3, 0, 2)) + solve(n - 3, 0, 0) + solve(n - 3, 1, 1) + solve(n - 3, 2, 2)<<endl;
    }

    return 0;
}
