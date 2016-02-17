#include <iostream>
#include <cstdio>
#define endl '\n'
using namespace std;

int rFind;
string s, t, currString;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    cin>>s>>t;
    for(int i = 0; i < s.size(); i++)
    {
        currString += s[i];

        if(currString.size() >= t.size() && currString.substr(currString.size() - t.size()) == t) currString.erase(currString.size() - t.size());
    }

    cout<<currString<<endl;
    return 0;
}
