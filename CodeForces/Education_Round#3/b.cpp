#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxM = 15;

int n, m, a, cnt[maxM], ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        cnt[a]++;
    }

    for(int i = 1; i < m; i++)
    {
        for(int j = i + 1; j <= m; j++)
        {
            ans += cnt[i] * cnt[j];
        }
    }

    cout<<ans<<endl;
    return 0;
}
