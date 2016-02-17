#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 5e4 + 5;

long long t, n, a[maxN], k, maxA;

long long answer(long long p)
{
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += a[i] / p;
    }

    return ans;
}
long long bSearch(long long p)
{
    long long le = 0, ri = maxA + 1, mid;

    while(le < ri)
    {
        mid = le + (ri - le + 1) / 2;

        if(answer(mid) < p) ri = mid - 1;
        else le = mid;
    }

    return le;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>n>>k;
        maxA = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];

            maxA = max(a[i], maxA);
        }

        cout<<bSearch(k)<<endl;
    }

    return 0;
}
