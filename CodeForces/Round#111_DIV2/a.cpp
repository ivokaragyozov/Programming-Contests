#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

int n, a[maxN], sum1, sum2, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum1 += a[i];
    }

    sort(a, a + n);

    for(int i = n - 1; i >= 0; i--)
    {
        sum1 -= a[i];
        sum2 += a[i];
        ans++;

        if(sum2 > sum1) break;
    }

    cout<<ans<<endl;
    return 0;
}

