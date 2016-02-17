#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool p;
string s, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    for(int i = 0; i < s.size(); )
    {
        while(i + 2 < s.size() && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
        {
            p = true;
            i += 3;
        }

        if(p && ans.size() != 0) ans += ' ';
        ans += s[i];
        i++;
        p = false;
    }

    if(ans[ans.size() - 1] == ' ') ans.erase(ans.size() - 1, 1);
    cout<<ans<<endl;
    return 0;
}
