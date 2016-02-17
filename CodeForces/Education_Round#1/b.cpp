#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int m, l, r, k;
string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>m;
    t = s;
    for(int i = 0; i < m; i++)
    {
        cin>>l>>r>>k;

        l--;
        r--;
        for(int j = l; j <= r; j++)
        {
            int ind = j + k % (r - l + 1);
            if(ind > r) ind = l + (ind - r) - 1;
            t[ind] = s[j];
        }

        s = t;
    }

    cout<<s<<endl;
    return 0;
}

