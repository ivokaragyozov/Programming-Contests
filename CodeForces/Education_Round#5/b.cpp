#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

int n, m, a[maxN][maxN], ans, currMin;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        currMin = INT_MAX;
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] < currMin) currMin = a[i][j];
        }

        if(currMin > ans) ans = currMin;
    }

    cout<<ans<<endl;
    return 0;
}
