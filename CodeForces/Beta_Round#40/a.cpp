#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>t;
    reverse(s.begin(), s.end());

    if(t == s) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
