#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1005;

int n, a[maxN], dp[maxN][maxN][2], sums[maxN], currGame;

int solve(int beg, int en, int player)
{
    if(beg == en) return a[beg];
    if(dp[beg][en][player] != -1) return dp[beg][en][player];


    int sum = sums[en];
    if(beg != 0) sum -= sums[beg - 1];

    if(player == 0)
    {
        int val1 = sum - solve(beg + 1, en, 1), val2 = sum - solve(beg, en - 1, 1);

        dp[beg][en][0] = max(val1, val2);
        return max(val1, val2);
    }
    else
    {
        int val1;

        if(a[beg] >= a[en]) val1 = sum - solve(beg + 1, en, 0);
        else val1 = sum - solve(beg, en - 1, 0);

        dp[beg][en][1] = val1;
        return val1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        cin>>n;
        currGame++;
        if(n == 0) break;


        for(int i = 0; i < n; i++)
        {
            cin>>a[i];

            sums[i] = a[i];
            if(i != 0) sums[i] += sums[i - 1];
        }

        memset(dp, -1, sizeof(dp));
        cout<<"In game "<<currGame<<", the greedy strategy might lose by as many as "<<2 * solve(0, n - 1, 0) - sums[n - 1]<<" points."<<endl;
    }

    return 0;
}
