#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long a, b, k, first, last;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k>>a>>b;

    first = ((a / k) + 1) * k;
    last = b - b % k;
    if(a % k == 0) first -= k;

    //cout<<first<<" "<<last<<endl;
    if(first - last > 0) cout<<(last - first) / k + 1<<endl;
    else cout<<0<<endl;
    return 0;
}
