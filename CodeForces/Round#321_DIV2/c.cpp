#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

bool hasCat[maxN + 1];
int n, m, x, y, answer;
vector<int> v[maxN + 1];

void dfs(int node, int currCnt, int parent)
{

	if(hasCat[node - 1]) currCnt++;
	else currCnt = 0;
	if(currCnt > m) return;

	bool isLeave = true;
	for(int i = 0; i < v[node].size(); i++)
	{
		if(v[node][i] != parent)
		{
			isLeave = false;
			dfs(v[node][i], currCnt, node);
		}
	}

	if(isLeave) answer++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>hasCat[i];
	}

	for(int i = 0; i < n - 1; i++)
	{
		cin>>x>>y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1, 0, -1);

	cout<<answer<<endl;
	return 0;
}
