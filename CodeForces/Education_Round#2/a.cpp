#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool p = true;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ',')
        {
            if(!p)
            curr = "";
        }
        else curr += a[i];
    }
}
