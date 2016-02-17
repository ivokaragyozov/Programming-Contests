#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool used[100010];
int n, a[50005], ans;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        used[a[i]] = true;
    }

    sort(a, a + n / 2, cmp);
    sort(a + n / 2, a + n);

    for(int i = 0; i < n / 2; i++)
    {
        for(int j = 2 * n; j > a[i]; j--)
        {
            if(!used[j])
            {
                used[j] = true;
                ans++;
                break;
            }
        }
    }
    for(int i = n / 2; i < n; i++)
    {
        for(int j = 1; j < a[i]; j++)
        {
            if(!used[j])
            {
                used[j] = true;
                ans++;
                break;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
