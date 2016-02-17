#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long x, y, m;

long long solve(long long p, long long q)
{
    if(p >= m || q >= m) return 0;
    if(p <= 0 && q <= 0) return -1;

    long long val1, val2;
    if(p <= q) val1 = solve(p + q, q) + 1;
    else val1 = solve(p, p + q) + 1;

    return val1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>x>>y>>m;

    long long ans = solve(x, y);
    cout<<(ans == -1 ? -1 : ans)<<endl;
    return 0;
}
