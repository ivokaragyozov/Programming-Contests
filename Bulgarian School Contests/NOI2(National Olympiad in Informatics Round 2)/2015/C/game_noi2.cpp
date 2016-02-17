/**
Ivo Karagyozov
NOI2 2015 C3 game
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int VAL_MAX = (1<<31)-1;

struct edge
{
    int vr, tg;
};

int n, m, k, used[20005], dist[20005];
vector<edge> v[20005];
priority_queue<edge> pq;

bool operator<(edge a, edge b)
{
    return a.tg>b.tg;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    for(int i=0; i<m; i++)
    {
        int a, b, p, t, tg;
        cin>>a>>b>>p>>t;
        tg=t-p;
        edge e;
        e.vr=a; e.tg=tg;
        v[b].push_back(e);
        e.vr=b;
        v[a].push_back(e);
    }
}
void dijkstra()
{
    edge tmp;
    tmp.vr=1; tmp.tg=0;
    pq.push(tmp);
    dist[1]=0;
    while(!pq.empty())
    {
        tmp=pq.top();
        pq.pop();
        int vr=tmp.vr;
        if(used[vr]==1)continue;
        used[vr]=1;
        for(int i=0; i<v[vr].size(); i++)
        {
            if(!used[v[vr][i].vr] && dist[v[vr][i].vr]>dist[vr]+v[vr][i].tg)
            {
                dist[v[vr][i].vr]=dist[vr]+v[vr][i].tg;
                edge e;
                e.vr=v[vr][i].vr; e.tg=dist[v[vr][i].vr];
                pq.push(e);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    for(int i=1; i<=n; i++)
    {
        dist[i]=VAL_MAX;
    }
    dijkstra();
    cout<<k-dist[n]<<endl;
    return 0;
}
