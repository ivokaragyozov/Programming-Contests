#include<iostream>
#define endl '\n'
using namespace std;

const int VAL_MAX=1<<31-1;

int n, l, p[105], r[105], q[105], f[105], dp[105];

void init()
{
    for(int i=1; i<=l; i++)
    {
        dp[i]=VAL_MAX;
    }
    dp[0]=0;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>l;
    for(int i=0; i<n; i++)
    {
        cin>>p[i]>>r[i]>>q[i]>>f[i];
    }
}
void solve()
{
    for(int a=0; a<=l; a++)
    {
        if(dp[a]==VAL_MAX)continue;
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<=f[i]; j++)
            {
                int earn;
                if(j<r[i])earn=j*p[i];
                else earn=j*q[i];

                if(dp[a]+earn<dp[a+j])
                {
                    dp[a+j]=dp[a]+earn;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    init();
    solve();

    cout<<dp[l]<<endl;
    return 0;
}
