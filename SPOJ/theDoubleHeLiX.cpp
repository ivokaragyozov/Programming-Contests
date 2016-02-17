#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

struct

int n, m, a[10005], b[10005], sumsA[10005], sumsB[10005], curSum;

int binarySearch(int target)
{
    int le = 0, ri = n-1;

    while(le <= ri)
    {
        int mid = (le+ri)/2;

        if(target > a[mid]) ri = mid-1;
        else if(target < a[mid]) le = mid+1;
        else return mid;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        cin>>n;
        if(n == 0) break;

        for(int i = 0; i < n; i++)
        {
            cin>>a[i];

            curSum += a[i];
            sumsA[i] = curSum;
        }

        curSum = 0;

        cin>>m;
        for(int i = 0; i < m; i++)
        {
            cin>>b[i];

            curSum += b[i];
            sumsB[i] = curSum;
        }

        sort(a, a+n);

        for(int i = 0; i < m; i++)
        {
            if(binarySearch(a[]))
        }
    }
}
