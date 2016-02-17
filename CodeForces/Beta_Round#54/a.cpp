#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int ind = 0;
string s, hello = "hello ";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == hello[ind]) ind++;
    }

    if(ind > 4) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
