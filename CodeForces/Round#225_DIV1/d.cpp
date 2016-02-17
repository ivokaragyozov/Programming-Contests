#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int maxN = 1000, maxSum = 10000;
const long long mod = 1e9 + 7;

long long n, a[maxN + 1], dp[maxN + 1][2*maxSum + 5], answer;

long long solve(int pos, int sum)
{
    if(pos == n+1)
    {
        if(sum == maxSum) return 1;
        else return 0;
    }
    if(dp[pos][sum] != -1) return dp[pos][sum];

    dp[pos][sum] = solve(pos + 1, sum + a[pos]) + solve(pos + 1, sum - a[pos]);

    if(sum == maxSum) dp[pos][sum]++;

    return dp[pos][sum] % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= n; i++)
    {
        answer += solve(i + 1, a[i] + maxSum) + solve(i + 1, -a[i] + maxSum);
        answer %= mod;
    }

    cout<<answer<<endl;
    return 0;
}
