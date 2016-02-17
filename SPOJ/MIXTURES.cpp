#include <iostream>
#include <climits>
#include <cstring>
#define endl '\n'
using namespace std;

const int maxN = 105, maxA = 104;

long long n, a[maxN], dp[maxA][maxA], colors[maxA][maxA];

long long solve(int beg, int en)
{
    if(beg == en) return 0;
    if(beg == en - 1) return a[beg] * a[en];
    if(dp[beg][en] != -1) return dp[beg][en];

    long long ans = INT_MAX;
    for(int k = beg; k < en; k++)
    {
        ans = min(ans, solve(beg, k) + solve(k + 1, en) + colors[beg][k] * colors[k + 1][en]);
    }

    dp[beg][en] = ans;
    return ans;
}
void preCompute()
{
    int currSum;
    for(int i = 0; i < n; i++)
    {
        currSum = 0;
        for(int j = i; j < n; j++)
        {
            currSum += a[j];
            colors[i][j] = currSum % 100;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>n)
    {
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        preCompute();

        memset(dp, -1, sizeof(dp));
        cout<<solve(0, n - 1)<<endl;
    }

    return 0;
}
