#include<iostream>
#include<queue>
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

int n, m;
queue<point> q;
int used[505][505];
point be, en;
bool p=false;

void bfs(point be, point en)
{
    q.push(be);
    while(!q.empty())
    {
        point tmp=q.front();
        q.pop();
        if(tmp.x+1<=n && (!used[tmp.x+1][tmp.y] || (tmp.x+1==en.x && tmp.y==en.y)))
        {
            if(tmp.x+1==en.x && tmp.y==en.y && used[tmp.x+1][tmp.y])
            {
                cout<<"YES"<<endl;
                p=true;
                return;
            }
            q.push(point(tmp.x+1, tmp.y));
            used[tmp.x+1][tmp.y]=1;
        }
        if(tmp.x-1>0 && (!used[tmp.x-1][tmp.y] || (tmp.x-1==en.x && tmp.y==en.y)))
        {
            if(tmp.x-1==en.x && tmp.y==en.y && used[tmp.x-1][tmp.y])
            {
                cout<<"YES"<<endl;
                p=true;
                return;
            }
            q.push(point(tmp.x-1, tmp.y));
            used[tmp.x-1][tmp.y]=1;
        }
        if(tmp.y+1<=m && (!used[tmp.x][tmp.y+1] || (tmp.x==en.x && tmp.y+1==en.y)))
        {
            if(tmp.x==en.x && tmp.y+1==en.y && used[tmp.x][tmp.y+1])
            {
                cout<<"YES"<<endl;
                p=true;
                return;
            }
            q.push(point(tmp.x, tmp.y+1));
            used[tmp.x][tmp.y+1]=1;
        }
        if(tmp.y-1>0 && (!used[tmp.x][tmp.y-1] || (tmp.x==en.x && tmp.y-1==en.y)))
        {
            if(tmp.x==en.x && tmp.y-1==en.y && used[tmp.x][tmp.y-1])
            {
                cout<<"YES"<<endl;
                p=true;
                return;
            }
            q.push(point(tmp.x, tmp.y-1));
            used[tmp.x][tmp.y-1]=1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char a;
            cin>>a;
            if(a=='X')used[i+1][j+1]=1;
        }
    }
    int a, b;
    cin>>a>>b;
    be=point(a, b);
    cin>>a>>b;
    en=point(a, b);
    bfs(be, en);
    if(p==false)cout<<"NO"<<endl;
    return 0;
}
