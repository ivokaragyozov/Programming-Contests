#include <iostream>
#define endl '\n'
using namespace std;

int n, cnt_ones, cnt_zeroes;
string s;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>s;
    for(int i=0; i<n; i++)
    {
        if(s[i] == '1')
        {
            cnt_ones++;
        }
        else
        {
            cnt_zeroes++;
        }
    }
}

int main()
{
    input();
    cout<<max(cnt_ones, cnt_zeroes)-min(cnt_ones, cnt_zeroes)<<endl;
    return 0;
}
