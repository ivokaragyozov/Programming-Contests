#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 4e5 + 5, maxC = 65;

bool vis[maxN];
int n, colors[maxN], a, b, nodes[maxN];
vector<int> graph[maxN];

void dfs(int node)
{
	int cntPerColor[maxC], currAns = 0;
	cntPerColor[colors[node]] = 1;

	for(int i = 0; i < graph[node].size(); i++)
	{
		if(!vis[graph[node][i]]) dfs(graph[node][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>colors[i];
	}

	for(int i = 0; i < n - 1; i++)
	{
		cin>>a>>b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	cntPerColor[colors[1]] = 1;
	vis[1] = true;
	dfs(1);
}
