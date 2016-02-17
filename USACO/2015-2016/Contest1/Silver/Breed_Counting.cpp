#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

int n, a, sums1[maxN], sums2[maxN], sums3[maxN], q, b;

int main()
{
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    for(int i = 1; i <= n; i++)
    {
        cin>>a;

        sums1[i] = sums1[i - 1];
        sums2[i] = sums2[i - 1];
        sums3[i] = sums3[i - 1];

        if(a == 1) sums1[i]++;
        else if(a == 2) sums2[i]++;
        else sums3[i]++;
    }

    for(int i = 0; i < q; i++)
    {
        cin>>a>>b;

        cout<<sums1[b] - sums1[a - 1]<<" "<<sums2[b] - sums2[a - 1]<<" "<<sums3[b] - sums3[a - 1]<<endl;
    }

    return 0;
}
