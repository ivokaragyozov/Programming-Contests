#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 5;

long long n, a, sums[maxN], maxNum = INT_MAX, startInd;
map<long long, int> currSums;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        sums[i] = a;
        if(i != 0) sums[i] += sums[i - 1];
    }

    currSums[0] = -1;
    for(int i = 0; i < n; i++)
    {
        if(currSums.find(sums[i]) != currSums.end())
        {
            if(i - currSums[sums[i]] < maxNum)
            {
                maxNum = i - currSums[sums[i]];
                startInd = currSums[sums[i]] + 1;
            }
        }

        currSums[sums[i]] = i;
    }

    if(maxNum != INT_MAX) cout<<startInd + 1<<" "<<maxNum<<endl;
    else cout<<-1<<endl;
    return 0;
}
