/**
Ivo Karagyozov
Proleten 2015 D1 robot
*/
#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

long long k, i, j, dp[100][100][100];

long long solve(int x, int y, int cntTimes)
{
    if(!cntTimes)
    {
        if(!x && !y) return 1;
        return 0;
    }
    if(dp[x+50][y+50][cntTimes] != -1) return dp[x+50][y+50][cntTimes];
    long long sum = solve(x-1, y, cntTimes-1)+solve(x+1, y, cntTimes-1)+solve(x, y-1, cntTimes-1)+solve(x, y+1, cntTimes-1);
    dp[x+50][y+50][cntTimes] = sum;
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k>>i>>j;
    memset(dp, -1, sizeof(dp));
    cout<<solve(i, j, k)<<endl;
    return 0;
}
