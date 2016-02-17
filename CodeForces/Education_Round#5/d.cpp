#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 5e5 + 5, maxA = 1e6 + 5;

bool used[maxA];
int n, k, sums[maxN], a, ans, ansLeft, ansRight;

int binarySearch(int target, int start)
{
    int le = start, ri = n - 1, mid, nearestLeft = -1;

    while(le <= ri)
    {
        mid = (le + ri) / 2;

        if(sums[mid] > target) ri = mid - 1;
        else
        {
            le = mid + 1;
            nearestLeft = mid;
        }
    }

    return nearestLeft;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        if(i != 0) sums[i] = sums[i - 1];
        if(!used[a]) sums[i]++;
        used[a] = true;
    }

    for(int i = 0; i < n; i++)
    {
        cout<<sums[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i < n; i++)
    {
        int ri = binarySearch(k + sums[i - 1] - 1, i);

        cout<<i<<" "<<sums[i]<<" "<<ri<<" "<<sums[ri]<<endl;

        if(ri == - 1) continue;

        if(ri - i + 1 > ans)
        {
            ans = ri - i + 1;
            ansLeft = i;
            ansRight = ri;
        }
    }

    cout<<ansLeft + 1<<" "<<ansRight + 1<<endl;
    return 0;
}
