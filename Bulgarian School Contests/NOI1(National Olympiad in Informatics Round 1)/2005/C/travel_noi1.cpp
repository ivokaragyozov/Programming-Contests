/**
Ivo Karagyozov
NOI1 2005 C1 travel
*/
#include<iostream>
#include<vector>
using namespace std;

bool used[100];
int par[100];
vector<int> nodes[100];
void dfs(int node)
{
    used[node] = true;
    for(int i=0; i<nodes[node].size(); i++)
    {
        if(used[nodes[node][i]] == false)
        {
            par[nodes[node][i]] = node;
            dfs(nodes[node][i]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int st, en;
    cin>>st>>en;
    while(1)
    {
        int node1, node2;
        cin>>node1>>node2;
        if(node1 == 0 && node2 == 0)break;
        nodes[node1].push_back(node2);
        nodes[node2].push_back(node1);
    }
    dfs(st);
    int road[100], ind = 0;
    int node = en;
    road[ind] = node;
    ind++;
    while(1)
    {
        road[ind] = par[node];
        node = road[ind];
        ind++;
        if(node == st)break;
    }
    for(int i = ind-1; i>=1; i--)
    {
        cout<<road[i]<<" ";
    }
    cout<<road[0]<<endl;
    return 0;
}
