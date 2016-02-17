#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

int n, i, a[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    sort(a, a + n);

    i = n - 1;
    for(i = n - 1; i >= 0; i--)
    {
        if(a[i] <= i) break;
    }

    cout<<i + 1<<endl;
    return 0;
}
