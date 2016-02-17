#include <iostream>
#define endl '\n'
using namespace std;

char a, b;
int n, table[26][26], cntDistinct, ans;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>s;
        cntDistinct = 0;
        a = 'z' + 1;
        b = 'z' + 1;
        for(int j = 0; j < s.size(); j++)
        {
            if(a != s[j] && b != s[j])
            {
                cntDistinct++;
                if(cntDistinct >= 3) break;

                if(a == 'z' + 1) a = s[j];
                else b = s[j];
            }
        }

        if(a > b) swap(a, b);

        //cout<<a<<" "<<b<<endl;

        if(cntDistinct == 1)
        {
            for(int j = 0; j < 26; j++)
            {
                table[a - 'a'][j] += s.size();
                if(j != a - 'a') table[j][a - 'a'] += s.size();

                //cout<<a - 'a'<<" "<<j<<" "<<table[a - 'a'][j]<<endl;

                if(table[a - 'a'][j] > ans) ans = table[a - 'a'][j];
            }
        }
        else if(cntDistinct == 2)
        {
            table[a - 'a'][b - 'a'] += s.size();
            table[b - 'a'][a - 'a'] += s.size();

            //cout<<a - 'a'<<" "<<b - 'a'<<" "<<table[a - 'a'][b - 'a']<<endl;

            if(table[a - 'a'][b - 'a'] > ans) ans = table[a - 'a'][b - 'a'];
        }
    }

    cout<<ans<<endl;
    return 0;
}
