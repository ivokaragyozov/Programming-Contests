#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int VAL_MAX=(1<<31)-1;

struct edge
{
    long long vr, tg;
};

vector<edge> v[5005];
priority_queue<edge> pq;
long long n, q, dist[5005], used[5005], dyn[5005][5005];

bool operator<(edge a, edge b)
{
    return a.tg>b.tg;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for(int i=0; i<n-1; i++)
    {
        int a, b, tg;
        edge e;
        cin>>a>>b>>tg;
        e.vr=a;
        e.tg=tg;
        v[b].push_back(e);
        e.vr=b;
        v[a].push_back(e);
    }
}
void dijkstra(int beg)
{
    edge tmp;
    tmp.vr=beg;
    tmp.tg=0;
    pq.push(tmp);
    dist[beg]=0;
    while(!pq.empty())
    {
        tmp=pq.top();
        pq.pop();
        if(used[tmp.vr]==1)continue;
        used[tmp.vr]=1;
        for(int i=0; i<v[tmp.vr].size(); i++)
        {
            if(used[v[tmp.vr][i].vr]==0 && dist[v[tmp.vr][i].vr]>dist[tmp.vr]+v[tmp.vr][i].tg)
            {
                dist[v[tmp.vr][i].vr]=dist[tmp.vr]+v[tmp.vr][i].tg;
                edge e;
                e.vr=v[tmp.vr][i].vr;
                e.tg=dist[v[tmp.vr][i].vr];
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
    for(int i=0; i<q; i++)
    {
        int a, b;
        cin>>a>>b;
        for(int j=1; j<=n; j++)
        {
            used[j]=0;
            dist[j]=VAL_MAX;
        }
        if(dyn[a][b]!=0)
        {
            cout<<dyn[a][b]<<endl;
            continue;
        }
        dijkstra(a);
        cout<<dist[b]<<endl;
        for(int j=1; j<=n; j++)
        {
            dyn[j][a]=dist[j];
            dyn[a][j]=dist[j];
        }
    }
    return 0;
}
