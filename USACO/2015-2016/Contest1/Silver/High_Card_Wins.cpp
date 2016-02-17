#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 50005;

bool used[2 * maxN], used2[2 * maxN];
int n, a[2 * maxN], b[2 * maxN], ind, ans;

int binarySearch(int index)
{
    int le = ind, ri = n - 1, mid, nearestRight = -1;

    while(le <= ri)
    {
        mid = (le + ri) / 2;

        if(b[mid] > a[index])
        {
            nearestRight = mid;
            ri = mid - 1;
        }
        else le = mid + 1;
    }

    return nearestRight;
}
int main()
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        used[a[i]] = true;
    }

    for(int i = 1; i <= 2 * n; i++)
    {
        if(!used[i]) b[ind++] = i;
    }

    sort(a, a + n);

    ind = 0;
    for(int i = 0; i < n; i++)
    {
        int ind1 = binarySearch(i);

        if(ind1 == -1) break;
        ind = ind1 + 1;
        ans++;
    }

    cout<<ans<<endl;
    return 0;
}
