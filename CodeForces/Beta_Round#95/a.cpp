#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] <= 'z' && s[i] >= 'a')
        {
            cout<<s<<endl;
            return 0;
        }
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z') t += (s[i] - 'A') + 'a';
        else t += (s[i] - 'a') + 'A';
    }

    cout<<t<<endl;
    return 0;
}
