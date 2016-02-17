#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int x, y, z, a, b, c, curr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>x>>y>>z>>a>>b>>c;

    if(a > x) curr -= a - x;
    else curr += ceil((x - a) / 2.0);

    if(b > y) curr -= b - y;
    else curr += ceil((y - b) / 2.0);

    if(c > z) curr -= c - z;
    else curr += ceil((z - c) / 2.0);


    if(x != a) curr--;
    if(y != b) curr--;
    if(z != c) curr--;

    if(curr == 0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
