#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

long long n, k, dp[maxN], a[maxN], curr = 1, ans, pascal[maxN][11], multi;

void fillPascal()
{
    pascal[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        pascal[i][0] = 1;
        for(int j = 1; j <= 11; j++)
        {
            pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    fillPascal();
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];

        multi = 1;
        curr = 1;
        for(int j =  i - 1; j >= 0; j--)
        {
            if(a[j] < a[i])
            {
                if(curr == dp[j] + 1) multi++;

                curr = max(dp[j] + 1, curr);
            }
        }
        dp[i] = curr;

        if(curr >= k + 1) ans += multi * pascal[curr - 1][k];
    }

    cout<<ans<<endl;
    return 0;
}
