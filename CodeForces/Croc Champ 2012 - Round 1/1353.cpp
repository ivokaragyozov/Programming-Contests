#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

long long s, dp[11][85];

long long solve(int n, int sum)
{
    if(sum < 0) return 0;
    if(n == 0 && sum > 9) return 0;
    if(dp[n][sum] != -1) return dp[n][sum];

    long long curSum = 0;
    for(int i = 0; i <= 9; i++)
    {
        curSum += solve(n-1, sum-i);
    }

    dp[n][sum] = curSum;
    return curSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));


    for(int i = 0; i <= 9; i++) dp[1][i] = 1;
    //dp[1][9] = 1;

    cin>>s;
    cout<<solve(9, s)+(s == 1 ? 1 : 0)<<endl;
    return 0;
}

