#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

long long n, a[maxN], sumsV[maxN], sumsU[maxN], m, type, l, r;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];

        sumsV[i] = a[i];
        if(i != 0) sumsV[i] += sumsV[i - 1];
    }

    sort(a, a + n);

    sumsU[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        sumsU[i] = sumsU[i - 1] + a[i];
    }

    cin>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>type>>l>>r;
        l--;
        r--;

        if(type == 1)
        {
            if(l == 0) cout<<sumsV[r]<<endl;
            else cout<<sumsV[r] - sumsV[l - 1]<<endl;
        }
        else
        {
            if(l == 0) cout<<sumsU[r]<<endl;
            else cout<<sumsU[r] - sumsU[l - 1]<<endl;
        }
    }

    return 0;
}
