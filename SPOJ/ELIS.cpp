#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 15;

int n, a[maxN], currCnt, maxCnt, dp[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        currCnt = 1;

        for(int j = i - 1; j >= 0; j--)
        {
            if(a[i] > a[j]) currCnt = max(currCnt, dp[j] + 1);
        }

        dp[i] = currCnt;
        maxCnt = max(currCnt, maxCnt);
    }

    cout<<maxCnt<<endl;
    return 0;
}
