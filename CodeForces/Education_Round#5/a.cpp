#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>t;

    int i = 0;
    while(s[i] == '0') i++;
    s = s.substr(i);

    i = 0;
    while(t[i] == '0') i++;
    t = t.substr(i);

    if(s.size() != t.size())
    {
        if(s.size() > t.size()) cout<<">"<<endl;
        else cout<<"<"<<endl;
    }
    else
    {
        if(s > t) cout<<">"<<endl;
        else if(s < t) cout<<"<"<<endl;
        else cout<<"="<<endl;
    }

    return 0;
}
