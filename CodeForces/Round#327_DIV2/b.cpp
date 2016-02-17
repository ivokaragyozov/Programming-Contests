#include <iostream>
#define endl '\n'
using namespace std;

int n, m;
string s;
char letters[26], a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 26; i++)
    {
        letters[i] = (char)(i + 'a');
    }

    cin>>n>>m>>s;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        for(int j = 0; j < 26; j++)
        {
            if(letters[j] == a) letters[j] = b;
            else if(letters[j] == b) letters[j] = a;
        }
    }

    for(int i = 0; i < s.size(); i++)
    {
        s[i] = letters[s[i]-'a'];
    }
    cout<<s<<endl;
    return 0;
}
