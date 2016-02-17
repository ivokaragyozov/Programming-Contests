/**
Ivo Karagyozov
1/10 correct
*/
#include<iostream>
#include<cstdio>
using namespace std;

const int VAL_MAX=1<<31-1;

int a, b, n, cost, m[505], routes[505][10005], mincost=VAL_MAX;

int main()
{
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>n;
    for(int i=0; i<n; i++)
    {
        cin>>cost>>m[i];
        for(int j=0; j<m[i]; j++)
        {
            int p;
            cin>>p;
            routes[i][p]=cost;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)continue;
            for(int k=0; k<10005; k++)
            {
                if(routes[i][k] && routes[j][k] && routes[i][k]+routes[j][k]<mincost)
                {
                    mincost=routes[i][k]+routes[j][k];
                    break;
                }
            }
        }
    }
    cout<<mincost<<endl;
    return 0;
}
