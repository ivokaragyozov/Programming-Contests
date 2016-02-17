#include <iostream>
#define endl '\n'
using namespace std;

int n, m, a[300005], startInd, curSum, maxSum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];

        curSum += a[i];
        while(curSum > m)
        {
            curSum -= a[startInd++];
        }
        if(curSum > maxSum) maxSum = curSum;
    }

    cout<<maxSum<<endl;
    return 0;
}
