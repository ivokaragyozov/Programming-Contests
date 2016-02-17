#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

int n, dp[maxN], a, maxLen;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        dp[a] = max(dp[a - 1] + 1, 1);
        maxLen = max(maxLen, dp[a]);
    }

    cout<<n - maxLen<<endl;
    return 0;
}
