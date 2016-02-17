#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool used[26];
int cnt;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        if(!used[s[i] - 'a'])
        {
            used[s[i] - 'a'] = true;
            cnt++;
        }
    }

    if(cnt % 2 != 0) cout<<"IGNORE HIM!"<<endl;
    else cout<<"CHAT WITH HER!"<<endl;
    return 0;
}
