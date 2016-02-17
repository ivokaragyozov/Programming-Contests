/**
Ivo Karagyozov
Proleten 2012 C1 paper
*/
#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;

struct point
{
    int x, y;

    point(){}
    point(int a, int b)
    {
        x=a;
        y=b;
    }
};

int n, m, k, ans=0;
vector<point> v[65][55];
bool used[65][55];

void init()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i>0)
            {
                v[i][j].push_back(point(i-1, j));
            }
            if(j<m-1)
            {
                v[i][j].push_back(point(i, j+1));
            }
            if(i<n-1)
            {
                v[i][j].push_back(point(i+1, j));
            }
            if(j>0)
            {
                v[i][j].push_back(point(i, j-1));
            }
        }
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k;
    init();
    for(int i=0; i<k; i++)
    {
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        used[a][b]=true;
    }
}
void dfs(int x, int y)
{
    used[x][y]=true;
    for(int i=0; i<v[x][y].size(); i++)
    {
        if(!used[v[x][y][i].x][v[x][y][i].y])
        {
            dfs(v[x][y][i].x, v[x][y][i].y);
        }
    }
}

int main()
{
    input();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!used[i][j])
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout<<ans<<endl;
}
