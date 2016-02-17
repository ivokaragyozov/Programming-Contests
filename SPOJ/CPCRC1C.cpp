#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a, b;
map<int, map<int, int> > dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        cin>>a>>b;
        if(a == -1 && b == -1) break;

        cout<<solve()
    }
}
