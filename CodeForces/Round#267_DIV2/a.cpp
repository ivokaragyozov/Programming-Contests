#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, p, q, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>p>>q;
        if(q - p >= 2) ans++;
    }

    cout<<ans<<endl;
    return 0;
}
