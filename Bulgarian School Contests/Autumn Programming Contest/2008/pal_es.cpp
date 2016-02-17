/**
Ivo Karagyozov
Esenen 2008 C1 pal
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, cnt[15], a;
string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        cnt[a]++;
    }

    while(cnt[1] > 1)
    {
        s += '1';
        cnt[1] -= 2;

        if(cnt[10] % 2 != 0 && cnt[1] == 2) break;
    }
    while(cnt[2] > 1)
    {
        s += '2';
        cnt[2] -= 2;
    }
    while(cnt[5] > 1)
    {
        s += '5';
        cnt[5] -= 2;
    }

    if(s[0] == '1')
    {
        for(int i = 0; i < cnt[10] / 2; i++)
        {
            s = "10" + s;
        }

        cnt[10] = cnt[10] % 2;
    }
    else
    {
        if(cnt[1] != 0)
        {
            for(int i = 0; i < cnt[10] / 2; i++)
            {
                s = s + "10";
            }

            cnt[10] = cnt[10] % 2;
        }
    }


    t = s;
    reverse(t.begin(), t.end());

    if(cnt[10] != 0 && cnt[1] != 0) s += "101";
    else if(cnt[10] != 0 && s[s.size() - 1] == '1') s += '0';
    else if(cnt[1] != 0) s += '1';
    else if(cnt[2] != 0) s += '2';
    else if(cnt[5] != 0) s += '5';

    if(s.size() == 0)
    {
        cout<<"No"<<endl;
        return 0;
    }

    cout<<s<<t<<endl;
    return 0;
}
