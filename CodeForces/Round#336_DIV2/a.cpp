#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105, maxS = 1005;

int n, s, currTime = -1, a, b, floors[maxS];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>s;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;
        floors[a] = max(floors[a], b);
    }

    for(int i = s; i > 0; i--)
    {
        currTime = max(currTime + 1, floors[i]);
    }
    currTime++;

    cout<<currTime<<endl;
    return 0;
}
