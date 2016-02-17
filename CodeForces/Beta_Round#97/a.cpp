#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

int n, a, pos[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        pos[a] = i + 1;
    }

    for(int i = 1; i <= n; i++)
    {
        cout<<pos[i]<<" ";
    }
    cout<<endl;

    return 0;
}
