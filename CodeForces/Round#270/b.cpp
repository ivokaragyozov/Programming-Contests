#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 2000;

int n, k, a[maxN + 5], answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    sort(a, a + n);

    for(int i = 0; i < n; i += k)
    {
        answer += a[n - i - 1] - 1;
    }

    cout<<2 * answer<<endl;
    return 0;
}
