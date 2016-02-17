#include <iostream>
#include <climits>
#include <algorithm>
#include <fstream>
#define endl '\n'
using namespace std;

struct number
{
    int cntSmaller, cntBigger;
};

int n, c[100005], cnt[100005], curSum, answer = INT_MAX, maxNum;
number numbers[100005];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>c[i];
        cnt[c[i]]++;

        if(c[i] > maxNum) maxNum = c[i];
    }

    sort(c, c+n);

    for(int i = 0; i < n; i++)
    {
        int nextInd = i+cnt[c[i]];
        curSum = i;

        for(int j = 2*c[i]+1; j <= maxNum; j++)
        {
            curSum += cnt[j];
        }

        if(curSum < answer) answer = curSum;
    }

    cout<<answer<<endl;
    return 0;
}
