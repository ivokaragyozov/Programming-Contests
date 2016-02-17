#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

long long n, a, b, lastA, lastB, dp[1005][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        lastA = a;
        lastB = b;

        cin>>a>>b;

        if(i == 0)
        {
            dp[i][0] = a;
            dp[i][1] = b;
        }
        else
        {
            dp[i][0] = max(dp[i-1][0]+abs(lastB-b)+a, dp[i-1][1]+abs(lastA-b)+a);
            dp[i][1] = max(dp[i-1][0]+abs(lastB-a)+b, dp[i-1][1]+abs(lastA-a)+b);
        }
    }

    cout<<max(dp[n-1][0], dp[n-1][1])<<endl;
    return 0;
}
