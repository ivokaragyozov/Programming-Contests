#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 1.5 * 1e5;

int n, k, a, sums[maxN], ans, ind;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        if(i != 0) sums[i] = sums[i - 1];
        sums[i] += a;
    }

    ans = sums[k - 1];
    ind = 0;
    for(int i = k; i < n; i++)
    {
        if(sums[i] - sums[i - k] < ans)
        {
            ans = sums[i] - sums[i - k];
            ind = i - k + 1;
        }
    }

    cout<<ind + 1<<endl;
    return 0;
}
