#include  <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

int n, m, a[maxN], cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    sort(a, a + n);

    for(int i = n - 1; i >= 0; i--)
    {
        m -= a[i];
        cnt++;

        if(m <= 0)
        {
            cout<<cnt<<endl;
            return 0;
        }
    }

    return 0;
}
