#include <iostream>
#define endl '\n'
using namespace std;

unsigned long long n, k, x[200005], sums[200005], maxRight[200005], maxRInd[200005], curSum, curMax, curInd, a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>x[i];

        curSum += x[i];
        if(i >= k) curSum -= x[i-k];

        sums[i] = curSum;
    }

    for(int i = n-1; i >= k; i--)
    {
        if(sums[i] >= curMax)
        {
            curMax = sums[i];
            curInd = i-k+1;
        }

        maxRight[i] = curMax;
        maxRInd[i] = curInd;
    }

    curMax = 0;

    for(int i = 0; i < n-2*k+1; i++)
    {
        unsigned long long sum = sums[i+k-1]+maxRight[i+2*k-1];

        if(sum > curMax)
        {
            curMax = sum;
            a = i;
            b = maxRInd[i+2*k-1];
        }
    }

    cout<<a+1<<" "<<b+1<<endl;
    return 0;
}
