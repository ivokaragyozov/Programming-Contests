#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const long long mod = 1000000007;

int n, k, l, a[1000005], dp[1000005];

long long solve(long long ind)
{
    if(ind == 0) return 1;
    if(dp[ind] != -1) return dp[ind];

    dp[ind] = 0;
    long long ind1 = ind-1;
    while(ind1 >= 0 && a[ind1] >= a[ind]-l)
    {
        dp[ind] = (dp[ind]+solve(ind1))%mod;
        ind1--;
    }
    return dp[ind]%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin>>n>>k>>l;
    a[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    a[++n] = k;

    cout<<solve(n)<<endl;
    return 0;
}
