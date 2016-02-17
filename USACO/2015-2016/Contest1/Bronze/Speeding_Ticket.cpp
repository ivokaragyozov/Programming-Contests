#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, maxSpeed[105], ind, a, b, ans, ind1;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;

        ind1 = ind + a;
        for(; ind < ind1; ind++)
        {
            maxSpeed[ind] = b;
        }
    }

    ind = 0;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;

        ind1 = ind + a;
        for(; ind < ind1; ind++)
        {
            if(maxSpeed[ind] < b && b - maxSpeed[ind] > ans) ans = b - maxSpeed[ind];
        }
    }

    cout<<ans<<endl;
    return 0;
}
