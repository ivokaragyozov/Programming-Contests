#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxM = 55;

int n, m, arr[maxM], ans = 1005;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>arr[i];
    }

    sort(arr, arr + m);

    for(int i = n - 1; i < m; i++)
    {
        if(arr[i] - arr[i - n + 1] < ans) ans = arr[i] - arr[i - n + 1];
    }

    cout<<ans<<endl;
    return 0;
}
