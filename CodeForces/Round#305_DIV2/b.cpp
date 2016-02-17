#include<iostream>
#define endl '\n'
using namespace std;

int n, m, q, x, y, rows[505], tmax=0, br=0;
bool state[505][505];

void solve(int x, int y)
{
    state[x-1][y-1]=!state[x-1][y-1];
    tmax=0;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(state[i][j-1])
            {
                if(tmax==0)tmax++;
                br=1;
                while(state[i][j-1] && state[i][j] && j<m)
                {
                    br++;
                    j++;
                }
                if(br>tmax)
                {
                    tmax=br;
                }
                br=0;
            }
        }
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>state[i][j];
        }
    }
    for(int i=0; i<q; i++)
    {
        cin>>x>>y;
        solve(x, y);
        cout<<tmax<<endl;
    }
}

int main()
{
    input();
    return 0;
}
