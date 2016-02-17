#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

int n, k, a[maxN], ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(n - i > k) ans = max(ans, a[i] + a[i + 1]), i++, k--;
        else ans = max(ans, a[i]), k--;
    }

    cout<<ans<<endl;
    return 0;
}
