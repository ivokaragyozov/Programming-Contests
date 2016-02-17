#include <iostream>
#define endl '\n'
using namespace std;

int t, n, k, numbers[105], dp[10000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>n>>k;
        for(int i = 0; i < n; i++)
        {
            cin>>numbers[i];
        }
    }
}
