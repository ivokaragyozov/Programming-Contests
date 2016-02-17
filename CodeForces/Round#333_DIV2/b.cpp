#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5, maxA = 1e5 + 5;

int n, a[maxN], ans = 1, currMin, currMax, inds[maxA], le, ri;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    currMin = currMax = a[0];
    inds[a[0]] = 0;
    le = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] >= currMax)
        {
            inds[a[i]] = i;
            currMax = a[i];

            if(currMax - currMin > 1)
            {
                le = inds[currMin] + 1;
                currMin = currMax - 1;
            }
        }
        if(a[i] <= currMin)
        {
            inds[a[i]] = i;
            currMin = a[i];

            if(currMax - currMin > 1)
            {
                le = inds[currMax] + 1;
                currMax = currMin + 1;
            }
        }

        if(i - le + 1 > ans) ans = i - le + 1;
    }

    cout<<ans<<endl;
    return 0;
}
