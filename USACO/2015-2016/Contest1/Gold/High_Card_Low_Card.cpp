#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 50005;

bool used[2 * maxN];
int n, a[maxN], b[maxN], ind, ans;

int binarySearchRight(int index)
{
    int le = ind, ri = n / 2 - 1, mid, nearestRight = -1;

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
int binarySearchLeft(int index)
{
    int le = n / 2, ri = ind, mid, nearestLeft = -1;

    while(le <= ri)
    {
        mid = (le + ri) / 2;

        if(b[mid] > a[index]) ri = mid - 1;
        else
        {
            nearestLeft = mid;
            le = mid + 1;
        }
    }

    return nearestLeft;
}
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        used[a[i]] = true;
    }

    for(int i = 2 * n; i >= 0; i--)
    {
        if(!used[i]) b[ind++] = i;
    }

    sort(a, a + n / 2);
    sort(a + n / 2, a + n, cmp);
    sort(b, b + n / 2);
    sort(b + n / 2, b + n);

    ind = 0;
    for(int i = 0; i < n / 2; i++)
    {
        int ind1 = binarySearchRight(i);

        if(ind1 == -1) break;
        ans++;
        ind = ind1 + 1;
    }

    ind = n - 1;
    for(int j = n / 2; j < n; j++)
    {
        int ind1 = binarySearchLeft(j);

        if(ind1 == -1) break;
        ans++;
        ind = ind1 - 1;
    }

    cout<<ans<<endl;
    return 0;
}

