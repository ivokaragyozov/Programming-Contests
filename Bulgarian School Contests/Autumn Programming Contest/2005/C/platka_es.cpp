/**
Ivo Karagyozov
Esenen 2005 C2 platka
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e4 + 5;

struct edge
{
    bool vis;
    int node, indRev;

    edge(){}
    edge(int node, int indRev)
    {
        vis = false;
        this->node = node;
        this->indRev = indRev;
    }
};

bool vis[maxN];
int n, m, a, b, startNode, cnt;
vector<edge> graph[maxN];
stack<int> st, path;

void dfs(int node)
{
    st.push(node);

    for(int i = 0; i < graph[node].size(); i++)
    {
        if(!graph[node][i].vis)
        {
            graph[node][i].vis = true;
            graph[graph[node][i].node][graph[node][i].indRev].vis = true;
            dfs(graph[node][i].node);
            break;
        }
    }
}
void dfs2(int node)
{
    vis[node] = true;

    for(int i = 0; i < graph[node].size(); i++)
    {
        if(!vis[graph[node][i].node]) dfs2(graph[node][i].node);
    }
}
void euler(int node)
{
    dfs(node);

    bool p = false;
    int currNode;

    while(!st.empty())
    {
        currNode = st.top();
        st.pop();

        for(int i = 0; i < graph[currNode].size(); i++)
        {
            if(!graph[currNode][i].vis)
            {
                dfs(currNode);
                p = true;
            }
        }


        if(!p) path.push(currNode);
        else p = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;

        graph[a].push_back(edge(b, graph[b].size()));
        graph[b].push_back(edge(a, graph[a].size() - 1));
    }

    startNode = 1;
    for(int i = 1; i <= n; i++)
    {
        if(graph[i].size() % 2 != 0)
        {
            startNode = i;
            break;
        }
    }

    dfs2(startNode);
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i]) cnt++;
    }


    if(cnt == 0)
    {
        euler(startNode);

        while(!path.empty())
        {
            cout<<path.top()<<" ";
            path.pop();
        }
    }
    else cout<<"Sorry Pesho "<<cnt<<endl;

    return 0;
}
