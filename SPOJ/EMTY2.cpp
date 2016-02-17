#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool p;
int t, currCnt;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>s;
        currCnt = 0;

        cout<<"Case "<<cs + 1<<": ";

        p = false;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == '0') currCnt++;
            else currCnt -= 2;

            if(currCnt < 0)
            {
                cout<<"no"<<endl;
                p = true;
                break;
            }
        }

        if(p) continue;
        else if(currCnt != 0) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }

    return 0;
}
