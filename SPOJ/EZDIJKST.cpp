#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e4 + 5;

struct edge
{
    int node, weight;

    edge(){}
    edge(int node, int weight)
    {
        this->node = node;
        this->weight = weight;
    }
};

bool vis[maxN];
int t, n, m, a, b, c, dist[maxN];
vector<edge> graph[maxN];
priority_queue<edge> pq;

void init()
{
    for(int i = 0; i <= maxN; i++)
    {
        vis[i] = 0;
        dist[i] = -1;
        graph[i].erase(graph[i].begin(), graph[i].end());
    }
}
void dijkstra(int beg)
{
    int node, weight;

    pq.push(edge(beg, 0));
    dist[beg] = 0;

    while(!pq.empty())
    {
        node = pq.top().node;
        weight = pq.top().weight;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = true;

        for(int i = 0; i < graph[node].size(); i++)
        {
            if(!vis[graph[node][i].node] && (dist[graph[node][i].node] > weight + graph[node][i].weight || dist[graph[node][i].node] == -1))
            {
                dist[graph[node][i].node] = weight + graph[node][i].weight;
                pq.push(edge(graph[node][i].node, dist[graph[node][i].node]));
            }
        }
    }
}
bool operator<(edge x, edge y)
{
    return x.weight > y.weight;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        init();

        cin>>n>>m;
        for(int i = 0; i < m; i++)
        {
            cin>>a>>b>>c;

            graph[a].push_back(edge(b, c));
        }

        cin>>a>>b;
        dijkstra(a);

        if(dist[b] != -1) cout<<dist[b]<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
