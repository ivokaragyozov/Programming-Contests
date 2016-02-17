#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, a, b, currCnt, maxCnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;

        currCnt = currCnt - a + b;
        if(currCnt > maxCnt) maxCnt = currCnt;
    }

    cout<<maxCnt<<endl;
    return 0;
}
