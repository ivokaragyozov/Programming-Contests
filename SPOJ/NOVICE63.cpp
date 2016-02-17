#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int t, n, dp[maxN][maxN][maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>n;

        cout<<solve(n, 0, 0)<<endl;
    }
}
