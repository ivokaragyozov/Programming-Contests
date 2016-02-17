#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, ans, currCnt;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>s;
    for(int i = 1; i < n; i++)
    {
        if(s[i] != s[i - 1])
        {
            ans += currCnt;
            currCnt = 0;
        }
        else currCnt++;
    }
    ans += currCnt;

    cout<<ans<<endl;
    return 0;
}
