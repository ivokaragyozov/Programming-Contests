#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, a, maxA, minA = 105, indMax, indMin, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        if(a > maxA)
        {
            maxA = a;
            indMax = i;
        }
        if(a <= minA)
        {
            minA = a;
            indMin = i;
        }
    }

    ans = indMax + (n - indMin - 1);
    if(indMin < indMax) ans--;

    cout<<ans<<endl;
    return 0;
}
