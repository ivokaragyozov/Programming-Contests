#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int maxN = 100, maxK = 10, mod = 1e8;

int n1, n2, k1, k2, dp[2][maxN + 5][maxN + 5][maxK + 5];

int solve(int type, int cntFoot, int cntHorse, int currCnt)
{
    if(cntFoot == 0 && cntHorse == 0) return 1;
    if(dp[type][cntFoot][cntHorse][currCnt] != -1) return dp[type][cntFoot][cntHorse][currCnt];

    int ans = 0;
    if(type == 0)
    {
        if(currCnt < k1 && cntFoot != 0) ans = (ans + solve(0, cntFoot - 1, cntHorse, currCnt + 1)) % mod;
        if(cntHorse != 0) ans = (ans + solve(1, cntFoot, cntHorse - 1, 1)) % mod;
    }
    else
    {
        if(currCnt < k2 && cntHorse != 0) ans = (ans + solve(1, cntFoot, cntHorse - 1, currCnt + 1)) % mod;
        if(cntFoot != 0) ans = (ans + solve(0, cntFoot - 1, cntHorse, 1)) % mod;
    }

    dp[type][cntFoot][cntHorse][currCnt] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n1>>n2>>k1>>k2;

    memset(dp, -1, sizeof(dp));
    cout<<(solve(0, n1 - 1, n2, 1) + solve(1, n1, n2 - 1, 1)) % mod<<endl;
    return 0;
}
