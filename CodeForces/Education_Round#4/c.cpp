#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int cnt, cnt2 = 0;
string s;
stack<char> opening;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '<' || s[i] == '{')
        {
            cnt++;
            opening.push(s[i]);
        }
        else
        {
            cnt--;
            if(cnt < 0)
            {
                cout<<"Impossible"<<endl;
                return 0;
            }

            char ch = opening.top();
            if(ch == '(') ch = ')';
            else if(ch == '[') ch = ']';
            else if(ch == '<') ch = '>';
            else ch = '}';

            if(ch != s[i])
            {
                cnt2++;
            }
            opening.pop();
        }
    }
    if(cnt != 0)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }

    cout<<cnt2<<endl;
    return 0;
}
