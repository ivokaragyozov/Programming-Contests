#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int k, l, m, n, d, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k>>l>>m>>n>>d;
    for(int i = 1; i <= d; i++)
    {
        if(i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) ans++;
    }

    cout<<ans<<endl;
    return 0;
}
