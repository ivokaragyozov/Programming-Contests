#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxS = 1e5;

int s, a[maxS], b[maxS], ind1, ind2, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    for(int i = 0; i < s; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i < s; i++)
    {
        cin>>b[i];
    }

    sort(a, a + s);
    sort(b, b + s);

    ind1 = ind2 = s - 1;
    while(ind2 >= 0 && ind1 >= 0)
    {
        while(ind1 >= 0 && a[ind1] >= b[ind2])
        {
            ind1--;
        }
        if(ind1 < 0) break;

        ans++;
        ind1--;
        ind2--;
    }

    cout<<ans<<endl;
    return 0;
}
