#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, p, q;

void dfs(int node)
{
    if(node == 1)
    {
        p = 1;
        q = 1;
        return;
    }

    dfs(node / 2);
    if(node % 2 == 0) q += p;
    else p += q;

    //cout<<node<<" "<<p<<" "<<q<<endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        cin>>n;
        if(n == 0) break;

        dfs(n);
        cout<<p<<"/"<<q<<endl;
    }

    return 0;
}
