#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int cnt1, cnt2, cnt3;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1') cnt1++;
        else if(s[i] == '2') cnt2++;
        else if(s[i] == '3') cnt3++;
    }

    if(cnt1 != 0) cout<<1;
    for(int i = 1; i < cnt1; i++)
    {
        cout<<"+1";
    }
    if(cnt2 != 0)
    {
        if(cnt1 != 0) cout<<"+";
        cout<<2;
    }
    for(int i = 1; i < cnt2; i++)
    {
        cout<<"+2";
    }
    if(cnt3 != 0)
    {
        if(cnt1 != 0 || cnt2 != 0) cout<<"+";
        cout<<3;
    }
    for(int i = 1; i < cnt3; i++)
    {
        cout<<"+3";
    }

    return 0;
}
