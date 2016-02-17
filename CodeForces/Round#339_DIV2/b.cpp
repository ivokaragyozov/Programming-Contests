#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool p;
long long n, cntZeros, cntOnes;
string s, ans, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        p = false;
        cntOnes = 0;
        cin>>s;

        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] != '1' && s[j] != '0')
            {
                p = true;
                break;
            }
            else if(s[j] == '0') cntZeros++;
            else cntOnes++;
        }

        if(p || cntOnes > 1) ans = s;
        else if(!p && cntOnes == 0)
        {
            cout<<0<<endl;
            return 0;
        }
        else if(ans == "") ans = "1";
    }

    t.resize(cntZeros, '0');
    cout<<ans<<t<<endl;
    return 0;
}
