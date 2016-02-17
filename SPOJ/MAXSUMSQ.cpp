#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

long long t, n, a, sums[maxN], minimal[maxN], currSum, maxSum, currCnt, cnt[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        maxSum = -1001;
        currCnt = 0;
        memset(cnt, 0, sizeof(cnt));
        cnt[0] = 1;

        cin>>n;
        for(int i = 1; i <= n; i++)
        {
            cin>>a;
            sums[i] = a + sums[i - 1];
            minimal[i] = min(minimal[i - 1], sums[i]);
            cnt[sums[i]]++;

            currSum = sums[i] - minimal[i - 1];

            cout<<i<<" "<<currSum<<" "<<cnt[currSum]<<endl;

            if(currSum > maxSum)
            {
                maxSum = currSum;
                currCnt = 1;
            }
            else if(currSum == maxSum) currCnt += cnt[minimal[i - 1]];
        }

        cout<<maxSum<<" "<<currCnt<<endl;
    }

    return 0;
}
