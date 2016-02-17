#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

int t, n, a[maxN], b[maxN], ind[maxN], p[maxN];

int binarySearch(int target, int ind1)
{
    int le = 1, ri = ind1, mid, nearestRight;

    while(le <= ri)
    {
        mid = (le + ri) / 2;

        if(p[mid] > target)
        {
            nearestRight = mid;
            ri = mid - 1;
        }
        else if(p[mid] < target) le = mid + 1;
        else return mid;
    }

    return nearestRight;
}
int LIS()
{
    int ind1 = 1;

    p[1] = b[0];
    for(int i = 1; i < n; i++)
    {
        if(b[i] >= p[ind1]) p[++ind1] = b[i];
        else
        {
            int right = binarySearch(b[i], ind1);

            p[right] = b[i];
        }
    }

    return ind1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            ind[a[i]] = i;
        }
        for(int i = 0; i < n; i++)
        {
            cin>>b[i];
            b[i] = ind[b[i]];
        }

        cout<<LIS()<<endl;
    }
}
