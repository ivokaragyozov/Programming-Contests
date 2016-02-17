#include <iostream>
#define endl '\n'
using namespace std;

int t, cnt;
string s, ans[6];

bool isTrue(int col)
{
    bool p;

    for(int i = 0; i < col; i++)
    {
        p = true;
        for(int j = 0; j < 12 / col; j++)
        {
            if(s[i + j * col] == 'O')
            {
                p = false;
                break;
            }
        }

        if(p) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int i = 0; i < t; i++)
    {
        cnt = 0;
        cin>>s;

        if(isTrue(12))
        {
            ans[cnt] = "1x12";
            cnt++;
        }
        if(isTrue(6))
        {
            ans[cnt] = "2x6";
            cnt++;
        }
        if(isTrue(4))
        {
            ans[cnt] = "3x4";
            cnt++;
        }
        if(isTrue(3))
        {
            ans[cnt] = "4x3";
            cnt++;
        }
        if(isTrue(2))
        {
            ans[cnt] = "6x2";
            cnt++;
        }
        if(isTrue(1))
        {
            ans[cnt] = "12x1";
            cnt++;
        }

        cout<<cnt;
        for(int i = 0; i < cnt; i++)
        {
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }
}
