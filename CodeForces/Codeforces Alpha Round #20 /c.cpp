#include <iostream>
#include <vector>
#include <queue>;
#include <cstring>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

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

bool used[maxN + 5];
int n, m, a, b, c, node, weight, dist[maxN + 5], parent[maxN + 5], road[maxN + 5], roadInd;
vector<edge> v[maxN + 5];
priority_queue<edge> pq;
edge curr;

bool operator<(edge a, edge b)
{
    return a.weight > b.weight;
}
void dijkstra()
{
    int len;
    dist[1] = 0;
    parent[1] = -1;
    pq.push(edge(1, 0));

    while(!pq.empty())
    {
        curr = pq.top();
        pq.pop();
        node = curr.node;
        weight = curr.weight;

        if(used[node]) continue;
        used[node] = 1;

        len = v[node].size();
        for(int i = 0; i < len; i++)
        {
            if(!used[v[node][i].node] && (dist[v[node][i].node] == -1 || weight + v[node][i].weight < dist[v[node][i].node]))
            {
                parent[v[node][i].node] = node;
                dist[v[node][i].node] = weight + v[node][i].weight;
                pq.push(edge(v[node][i].node, dist[v[node][i].node]));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;

        v[a].push_back(edge(b, c));
        v[b].push_back(edge(a, c));
    }

    memset(dist, -1, sizeof(dist));

    dijkstra();

    if(dist[n] == -1)
    {
        cout<<-1<<endl;
        return 0;
    }

    int currNode = n;
    while(currNode != -1)
    {
        road[roadInd++] = currNode;
        currNode = parent[currNode];
    }

    for(int i = roadInd - 1; i >= 0; i--)
    {
        if(i != 0) cout<<road[i]<<" ";
        else cout<<road[i]<<endl;
    }
    return 0;
}
