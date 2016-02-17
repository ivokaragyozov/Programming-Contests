#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define endl '\n'
using namespace std;

int v, e, numberOfComponent, nodeComponent[5005], a[10000], b[10000], answer[5005], ind;
bool used[5005], hasOutEdges[5005];
vector<int> graph[5005], reversedGraph[5005];
stack<int> nodes;

void init()
{
    for(int i = 0; i <= v; i++)
    {
        graph[i].erase(graph[i].begin(), graph[i].end());
        reversedGraph[i].erase(reversedGraph[i].begin(), reversedGraph[i].end());
        used[i] = 0;
        hasOutEdges[i] = 0;
    }
    numberOfComponent = 0;
    ind = 0;
}
void dfsGraph(int beg)
{
    used[beg] = 1;
    for(int i = 0; i < graph[beg].size(); i++)
    {
        if(!used[graph[beg][i]]) dfsGraph(graph[beg][i]);
    }
    nodes.push(beg);
}
void dfsReversedGraph(int beg)
{
    used[beg] = 1;
    nodeComponent[beg] = numberOfComponent;
    for(int i = 0; i < reversedGraph[beg].size(); i++)
    {
        if(!used[reversedGraph[beg][i]]) dfsReversedGraph(reversedGraph[beg][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        cin>>v;
        if(!v) break;
        cin>>e;

        init();

        for(int i = 0; i < e; i++)
        {
            cin>>a[i]>>b[i];
            graph[a[i]].push_back(b[i]);
            reversedGraph[b[i]].push_back(a[i]);
        }

        for(int i = 1; i <= v; i++)
        {
            if(!used[i]) dfsGraph(i);
        }

        memset(used, 0, sizeof(used));

        while(!nodes.empty())
        {
            int tmp = nodes.top();
            nodes.pop();

            if(!used[tmp])
            {
                dfsReversedGraph(tmp);
                numberOfComponent++;
            }
        }

        for(int i = 0; i < e; i++)
        {
            if(nodeComponent[a[i]] != nodeComponent[b[i]])hasOutEdges[nodeComponent[a[i]]] = true;
        }

        for(int i = 1; i <= v; i++)
        {
            if(!hasOutEdges[nodeComponent[i]]) answer[ind++] = i;
        }

        if(ind)
        {
            cout<<answer[0];
        }
        for(int i = 1; i < ind; i++)
        {
            cout<<" "<<answer[i];
        }
        cout<<endl;
    }

    return 0;
}
