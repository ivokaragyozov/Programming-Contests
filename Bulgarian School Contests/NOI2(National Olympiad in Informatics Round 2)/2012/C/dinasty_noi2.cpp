#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 10005;

bool p;
int n, currMax;
string father[maxN], son, ans;
map<string, string> m;
map<string, vector<string> > graph;
map<string, int> used;

int dfs(string s)
{
	if(used[s] != 0) return used[s];

	int currAns = 1;
	for(int i = 0; i < graph[s].size(); i++)
	{
		currAns += dfs(graph[s][i]);
	}
	
	used[s] = currAns;
	return currAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	p = false;

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>father[i]>>son;
		if(p) continue;

		graph[father[i]].push_back(son);

		if(m.find(son) != m.end())
		{
			if(m[son] != father[i])
			{
				ans = son;
				p = true;
			}
		}
		else m[son] = father[i];
	}

	if(p)
	{
		cout<<ans<<endl;
		return 0;
	}

	for(int i = 0; i < n; i++)
	{
		if(used[father[i]] != 0) continue;

		used[father[i]] = dfs(father[i]);

		if(used[father[i]] > currMax)
		{
			currMax = used[father[i]];
			ans = father[i];
		}
	}

	cout<<ans<<endl;
	return 0;
}
