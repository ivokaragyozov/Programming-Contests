#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a, b, c, d;
double p, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b>>c>>d;

    p = (double)a / b;
    q = (1 - (double)c / d) * (1 - (double)a / b);

    cout<<fixed<<setprecision(9);
    cout<<p / (1 - q)<<endl;
    return 0;
}
