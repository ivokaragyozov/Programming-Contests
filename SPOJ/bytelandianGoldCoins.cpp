#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

long long n;
map<long long, long long> dp;

long long maxPos(long long a)
{
    if(dp.find(a) != dp.end()) return dp[a];

    long long val1 = maxPos(a/2)+maxPos(a/3)+maxPos(a/4), val2 = a;

    dp[a] = max(val1, val2);
    return dp[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 0;
    dp[1] = 1;

    while(cin>>n)
    {
        cout<<maxPos(n)<<endl;
    }

    return 0;
}
