#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a, b, n;

int gcd(int x, int y)
{
    int r;
    while(y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b>>n;

    while(1)
    {
        if(n - gcd(a, n) < 0)
        {
            cout<<1<<endl;
            return 0;
        }
        else n -= gcd(a, n);
        if(n - gcd(b, n) < 0)
        {
            cout<<0<<endl;
            return 0;
        }
        else n -= gcd(b, n);
    }

    return 0;
}
