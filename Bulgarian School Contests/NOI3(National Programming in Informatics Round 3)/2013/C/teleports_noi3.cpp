/**
Ivo Karagyozov
NOI3 2013 C2 teleports
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct point
{
    int x, y;
    point(){};
    point(int a, int b)
    {
        x=a;
        y=b;
    }
};

int bx, by, ex, ey, beg, en, n, ind=0, ans, use[10005], route[10005];
bool isPossible=false;
point used[10005];
vector<int> v[10005];
queue<int> q;

int hesh(int x, int y)
{
    for(int i=0; i<ind; i++)
    {
        if(used[i].x==x && used[i].y==y)return i;
    }
    used[ind]=point(x, y);
    return ind++;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>bx>>by>>ex>>ey;
    beg=hesh(bx, by);
    en=hesh(ex, ey);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>bx>>by>>ex>>ey;
        int ind1=hesh(bx, by), ind2=hesh(ex, ey);
        v[ind1].push_back(ind2);
        v[ind2].push_back(ind1);
    }
}
void bfs(int beg, int en)
{
    if(beg==en)
    {
        ans=0;
        isPossible=true;
        return;
    }
    q.push(beg);
    route[beg]=0;
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        for(int i=0; i<v[tmp].size(); i++)
        {
            if(v[tmp][i]==en)
            {
                isPossible=true;
                ans=route[tmp]+1;
                return;
            }
            if(use[v[tmp][i]]==0)
            {
                use[v[tmp][i]]=1;
                q.push(v[tmp][i]);
                route[v[tmp][i]]=route[tmp]+1;
            }
        }
    }
}

int main()
{
    input();
    bfs(beg, en);
    ans*=10;
    if(!isPossible)cout<<"no solution"<<endl;
    else cout<<ans<<endl;
    return 0;
}
