/**
Ivo Karagyozov
12/12 correct
*/
#include<iostream>
#include<cstdio>
using namespace std;

const int MAX_VAL=1<<31-1;

int a, b, n, mincost=MAX_VAL;

int main()
{
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>n;
    for(int i=0; i<n; i++)
    {
        int cost, m, p;
        bool p1=false;
        cin>>cost>>m;
        for(int j=0; j<m; j++)
        {
            cin>>p;
            if(p==a)
            {
                p1=true;
            }
            else if(p==b)
            {
                if(p1 && cost<mincost)
                {
                    mincost=cost;
                }
            }
        }
    }
    if(mincost==MAX_VAL)cout<<-1<<endl;
    else cout<<mincost<<endl;
    return 0;
}
