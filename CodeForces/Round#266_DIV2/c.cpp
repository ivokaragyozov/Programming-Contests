#include <iostream>
#define endl '\n'
using namespace std;

long long n, a[500005], curSum, totalSum, sumInPart, dp[500005], sum[500005], answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        curSum += a[i];
    }

    totalSum = curSum;
    curSum = 0;

    if(totalSum%3 != 0)
    {
        cout<<0<<endl;
        return 0;
    }
    else sumInPart = totalSum/3;

    for(int i = 0; i < n; i++)
    {
        if(totalSum-curSum == sumInPart) dp[i] = 1;
        curSum += a[i];
    }

    sum[n-1] = dp[n-1];
    for(int i = n-1; i >=0; i--) sum[i] = sum[i+1]+dp[i];

    curSum = 0;
    for(int i = 0; i < n-2; i++)
    {
        curSum += a[i];

        if(curSum == sumInPart) answer += sum[i+2];
    }

    cout<<answer<<endl;
    return 0;
}
