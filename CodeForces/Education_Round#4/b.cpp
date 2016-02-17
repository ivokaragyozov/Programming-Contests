#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 5;

long long n, a, pos[maxN], ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        pos[a] = i;
    }

    for(int i = 2; i <= n; i++)
    {
        ans += abs(pos[i - 1] - pos[i]);
    }

    cout<<ans<<endl;
    return 0;
}
