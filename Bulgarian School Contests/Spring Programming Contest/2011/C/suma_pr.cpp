/**
Ivo Karagyozov
Proleten 2011 C2 suma
*/
#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

const int VAL_MAX=1<<31-1;

int n, m, u, v, row[3005][3005], col[3005][3005], board[3005][3005], ans=VAL_MAX;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>u>>v;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>board[i][j];
        }
    }
}

void init_rows()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(j!=0)row[i][j]=row[i][j-1]+board[i][j];
            else row[i][j]=board[i][j];
            if(j>=v)row[i][j]-=board[i][j-v];
        }
    }
}
void init_cols()
{
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(i!=0)col[i][j]=col[i-1][j]+row[i][j];
            else col[i][j]=row[i][j];
            if(i>=u)col[i][j]-=row[i-u][j];
            if(abs(col[i][j])<ans && i>=u-1 && j>=v-1)
            {
                ans=abs(col[i][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    init_rows();
    init_cols();
    cout<<ans<<endl;
    return 0;
}
