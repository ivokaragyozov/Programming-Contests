#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool p;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '0')
        {
            s.erase(i, 1);
            p = true;
            break;
        }
    }

    if(!p) s.erase(0, 1);

    cout<<s<<endl;
    return 0;
}
