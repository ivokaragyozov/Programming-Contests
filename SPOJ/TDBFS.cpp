#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1005;

bool vis[maxN];
int t, n, m, a, v, type, ind;
vector<int> graph[maxN];
queue<int> q;

void init()
{
    for(int i = 1; i <= n; i++)
    {
        graph[i].erase(graph[i].begin(), graph[i].end());
    }
}
void dfs(int n)
{
    cout<<n<<" ";
    vis[n] = true;

    for(int i = 0; i < graph[n].size(); i++)
    {
        if(!vis[graph[n][i]]) dfs(graph[n][i]);
    }
}
void bfs(int n)
{
    int node;
    q.push(n);

    while(!q.empty())
    {
        node = q.front();
        q.pop();

        if(vis[node]) continue;
        vis[node] = true;

        cout<<node<<" ";

        for(int i = 0; i < graph[node].size(); i++)
        {
            if(!vis[graph[node][i]]) q.push(graph[node][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 1; cs <= t; cs++)
    {
        cin>>n;

        init();

        for(int i = 1; i <= n; i++)
        {
            cin>>ind>>m;

            for(int j = 0; j < m; j++)
            {
                cin>>a;

                graph[ind].push_back(a);
            }
        }

        cin>>v>>type;
        cout<<"graph "<<cs<<endl;
        while(v != 0)
        {
            memset(vis, 0, sizeof(vis));
            if(type == 1) bfs(v);
            else dfs(v);

            cout<<endl;

            cin>>v>>type;
        }
    }
}
