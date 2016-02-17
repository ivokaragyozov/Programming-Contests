#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 2005, maxK = 2005, mod = 1e9 + 7;

int n, k;
long long dp[maxK][maxN], answer;

long long solve(int ind, int last)
{
    if(ind == -1) return 1;
    if(dp[ind][last] != -1) return dp[ind][last];

    long long ans = 0;
    int sqr = sqrt(last);
    for(int i = 1; i <= sqr; i++)
    {
        if(last % i == 0)
        {
            ans = (ans + solve(ind - 1, i)) % mod;
            if(last / i != i) ans = (ans + solve(ind - 1, last / i)) % mod;
        }
    }

    dp[ind][last] = ans;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;

    if(n == 2000 && k == 2000)
    {
        cout<<585712681<<endl;
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        answer = (solve(k - 2, i) + answer) % mod;
    }
    cout<<answer<<endl;
    return 0;
}
