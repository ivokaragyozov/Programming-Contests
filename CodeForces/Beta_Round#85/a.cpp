#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>t;
    for(int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }
    for(int i = 0; i < t.size(); i++)
    {
        t[i] = tolower(t[i]);
    }

    if(s < t) cout<<-1<<endl;
    else if(s > t) cout<<1<<endl;
    else cout<<0<<endl;

    return 0;
}
