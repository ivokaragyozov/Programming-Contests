#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, dp[2][5005], curInd = 1, otherInd = 0;
string s, reversed;

int sizeOfLCS()
{
    s = " "+s;
    reversed = " "+reversed;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[i] == reversed[j]) dp[curInd][j] = dp[otherInd][j-1]+1;
            else dp[curInd][j] = max(dp[otherInd][j], dp[curInd][j-1]);
        }

        swap(curInd, otherInd);
    }

    //cout<<curInd<<" "<<otherInd<<" "<<dp[curInd][n]<<" "<<dp[otherInd][n]<<endl;

    return dp[otherInd][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>s;

    reversed = s;
    reverse(reversed.begin(), reversed.end());

    cout<<n-sizeOfLCS()<<endl;
    return 0;
}
