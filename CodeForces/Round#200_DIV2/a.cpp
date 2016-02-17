#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

int n, ans = 1;
string s[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>s[i];

        if(i > 0)
        {
            if(s[i - 1] != s[i]) ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}
