#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int currCnt = 1;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i - 1]) currCnt++;
        else currCnt = 1;

        if(currCnt >= 7)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    if(currCnt > 7)
    {
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;
    return 0;
}
