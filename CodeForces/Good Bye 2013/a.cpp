#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a, b, c, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>b;

    while(1)
    {
        if(a == 0 && c < b) break;

        if(c >= b)
        {
            c -= b;
            a++;
        }
        a--;
        c++;
        ans++;
    }

    cout<<ans<<endl;
    return 0;
}
