#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

long long n, a, dp[100005], f[100005], maxA;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        dp[a]++;
        if(a > maxA) maxA = a;
    }

    f[0] = 0;
    f[1] = dp[1];
    for(int i = 2; i <= maxA; i++) f[i] = max(f[i-1], f[i-2]+1LL*dp[i]*i);

    cout<<f[maxA]<<endl;
    return 0;
}
