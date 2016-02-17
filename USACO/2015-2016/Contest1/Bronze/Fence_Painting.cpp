#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a, b, c, d;

int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b>>c>>d;

    if((b > c && a < d) || (d > a && c < b)) cout<<max(b, d) - min(a, c)<<endl;
    else cout<<b - a + d - c<<endl;
    return 0;
}
