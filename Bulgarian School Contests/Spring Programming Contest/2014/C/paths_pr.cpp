/**
Ivo Karagyozov
Proleten 2014 C1 paths
*/
#include<iostream>
#define endl '\n'
using namespace std;

const int VAL_MAX=1<<31-1;

long long n, m, g[627][627], dp[627][627], q;

void init()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            g[i][j]=VAL_MAX;
            dp[i][j]=0;
        }
    }
}
void floyd()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int a=1; a<=n; a++)
            {
                if(g[i][j]+g[i][a]<g[j][a])
                {
                    g[j][a]=g[i][j]+g[i][a];
                    dp[j][a]=dp[i][j]*dp[i][a];
                }
                else if(g[i][j]+g[i][a]==g[j][a])
                {
                    dp[j][a]+=dp[i][j]*dp[i][a];
                }
            }
        }
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    init();
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a][b]=1;
        g[b][a]=1;
        dp[a][b]=1;
        dp[b][a]=1;
    }
    floyd();
    cin>>q;
    for(int i=0; i<q; i++)
    {
        int a, b;
        cin>>a>>b;
        if(i!=q-1)cout<<dp[a][b]<<" ";
        else cout<<dp[a][b]<<endl;
    }
}

int main()
{
    input();
}
