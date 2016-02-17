#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

int n, a[maxN + 5], ans;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    sort(a, a + n, cmp);

    for(int i = 0; i < n; i++)
    {
        if(i + 1 >= n)
        {
            ans += a[i];
        }
        else if(i + 2 >= n)
        {
            ans += a[i] + a[i + 1];
            i++;
        }
        else
        {
            ans += a[i] + a[i + 1];
            i += 2;
        }
    }


    cout<<ans<<endl;
    return 0;
}
