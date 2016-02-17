#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

const int maxK = 100;

int n, k, cnt[maxK + 5], a, average, ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        cnt[a]++;
    }

    average = n / k;

    for(int i = 1; i <= k; i++)
    {
        ans += abs(average - cnt[i]);
    }

    cout<<ans / 2<<endl;
    return 0;
}
