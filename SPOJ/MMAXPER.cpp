#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int maxN = 1005;

int n, w[maxN], h[maxN], dp[maxN][maxN];

int solve(int rect, int height)
{
    if(rect ==  -1) return 0;
    if(dp[rect][height] != -1) return dp[rect][height];

    int val1, val2;

    val1 = w[rect];
    if(rect != 0) val1 += h[rect];
    if(rect != n - 1)
    {
        if(h[rect] > height) val1 += h[rect] - 2 * height;
        else val1 -= h[rect];
    }
    val1 += solve(rect - 1, h[rect]);

    val2 = h[rect];
    if(rect != 0) val2 += w[rect];
    if(rect != n - 1)
    {
        if(w[rect] > height) val2 += w[rect] - 2 * height;
        else val2 -= w[rect];
    }
    val2 += solve(rect - 1, w[rect]);

    dp[rect][height] = max(val1, val2);
    return dp[rect][height];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>w[i]>>h[i];
    }

    memset(dp, -1, sizeof(dp));
    cout<<solve(n - 1, 0)<<endl;
    return 0;
}
