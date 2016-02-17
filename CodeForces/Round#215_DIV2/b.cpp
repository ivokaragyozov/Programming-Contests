#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5, maxA = 1e5 + 5;

bool used[maxA];
int n, m, a[maxN], l, dp[maxN], curr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    for(int i = n - 1; i >= 0; i--)
    {
        if(!used[a[i]]) curr++;

        dp[i] = curr;
        used[a[i]] = true;
    }

    for(int i = 0; i < m; i++)
    {
        cin>>l;
        cout<<dp[l - 1]<<endl;
    }

    return 0;
}
