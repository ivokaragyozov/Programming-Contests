/**
Ivo Karagyozov
NOI1 2010 B2 pic
*/
#include<iostream>
#define endl '\n'
using namespace std;

int n, m, br=0;
bool table[105][105], p=false;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>table[i][j];
        }
    }
}
void dfs(int i, int j)
{
    if(i==0 || j==0 || i==n-1 || j==m-1)
    {
        p=false;
    }
    table[i][j]=0;
    if(i-1>=0 && table[i-1][j])
    {
        dfs(i-1, j);
    }
    if(i-1>=0 && j+1<=m-1 && table[i-1][j+1])
    {
        dfs(i-1, j+1);
    }
    if(j+1<=m-1 && table[i][j+1])
    {
        dfs(i, j+1);
    }
    if(j+1<=m-1 && i+1<=n-1 && table[i+1][j+1])
    {
        dfs(i+1, j+1);
    }
    if(i+1<=n-1 && table[i+1][j])
    {
        dfs(i+1, j);
    }
    if(i+1<=n-1 && j-1>=0 && table[i+1][j-1])
    {
        dfs(i+1, j-1);
    }
    if(j-1>=0 && table[i][j-1])
    {
        dfs(i, j-1);
    }
    if(j-1>=0 && i-1>=0 && table[i-1][j-1])
    {
        dfs(i-1, j-1);
    }
}
void output()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<br<<endl;
}

int main()
{
    input();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(table[i][j])
            {
                p=true;
                dfs(i, j);
                if(p)br++;
            }
        }
    }
    output();
    return 0;
}
