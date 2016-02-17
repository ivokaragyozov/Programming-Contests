#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e4 + 5;

bool used[maxN * 2][maxN * 2];
int n, a[maxN], cnt[maxN * 2], ans, ind, currCnt;

int binarySearch(int target)
{
    int le = 0, ri = n - 1, mid;

    while(le <= ri)
    {
        mid = (le + ri) / 2;

        if(target > a[mid]) le = mid + 1;
        else if(target < a[mid]) ri = mid - 1;
        else return mid;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        cnt[a[i] + 10000]++;
    }

    sort(a, a + n);
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(used[a[i] + 10000][a[j] + 10000]) continue;
            ind = binarySearch(-(a[i] + a[j]));

            if(ind == -1) continue;

            currCnt = cnt[a[ind] + 10000];

            if(ind == i) currCnt--;
            if(ind == j) currCnt--;

            if(currCnt == 0) continue;

            used[a[i] + 10000][a[j] + 10000] = true;
            ans += currCnt;
        }
    }

    cout<<ans / 2<<endl;
    return 0;
}
