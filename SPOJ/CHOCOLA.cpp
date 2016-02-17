#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1005, maxM = 1005;

int t, n, m, x[maxN], y[maxM];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 1; cs <= t; cs++)
    {
        cin>>n>>m;
        for(int i = 0; i < n - 1; i++)
        {
            cin>>x[i];
        }
        for(int j = 0; j < m - 1; j++)
        {
            cin>>y[i];
        }

        cout<<solve(0, 0, n - 1, m - 1);
    }
}
