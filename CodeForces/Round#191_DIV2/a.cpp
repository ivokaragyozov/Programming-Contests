#include <iostream>
#define endl '\n'
using namespace std;

int n, a[105], curSum, maxSum, cntOnes[105], totalCnt, curCntOnes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        curCntOnes += a[i];
        cntOnes[i] = curCntOnes;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            totalCnt = j-i+1;
            curCntOnes = cntOnes[j]-cntOnes[i]+(a[i] == 1 ? 1 : 0);
            curSum = cntOnes[n-1]-curCntOnes+(totalCnt-curCntOnes);

            if(curSum > maxSum) maxSum = curSum;
        }
    }

    cout<<maxSum<<endl;
    return 0;
}
