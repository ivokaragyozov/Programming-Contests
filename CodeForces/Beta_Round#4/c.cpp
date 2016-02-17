#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

int n;
string s;
map<string, int> cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>s;

        if(cnt.find(s) == cnt.end())
        {
            cout<<"OK"<<endl;
            cnt[s] = 1;
        }
        else
        {
            cout<<s<<cnt[s]<<endl;
            cnt[s]++;
        }
    }

    return 0;
}
