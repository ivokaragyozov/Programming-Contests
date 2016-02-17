#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

bool vis[maxN];
char ch;
int t, n, ans, node;
vector<int> graph[maxN], reversedGraph[maxN];
stack<int> st;

void init()
{
    for(int i = 1; i <= n; i++)
    {
        graph[i].erase(graph[i].begin(), graph[i].end());
        reversedGraph[i].erase(reversedGraph[i].begin(), reversedGraph[i].end());
    }

    ans = 0;
}

void dfs(int n)
{
    vis[n] = true;

    for(int i = 0; i < graph[n].size(); i++)
    {
        if(!vis[graph[n][i]]) dfs(graph[n][i]);
    }

    st.push(n);
}
void dfs2(int n)
{
    vis[n] = true;

    for(int i = 0; i < reversedGraph[n].size(); i++)
    {
        if(!vis[reversedGraph[n][i]]) dfs2(reversedGraph[n][i]);
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
            for(int j = 1; j <= n; j++)
            {
                cin>>ch;

                if(ch == 'Y')
                {
                    graph[i].push_back(j);
                    reversedGraph[j].push_back(i);
                }
            }
        }

        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i]) dfs(i);
        }

        memset(vis, 0, sizeof(vis));
        while(!st.empty())
        {
            node = st.top();
            st.pop();

            if(!vis[node])
            {
                dfs2(node);
                ans++;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
