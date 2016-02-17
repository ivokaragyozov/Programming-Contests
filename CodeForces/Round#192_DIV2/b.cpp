#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 1e3;

bool p[maxN + 1];
int n, m, x, y, currNode;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i = 0; i < m; i++)
	{
		cin>>x>>y;
		p[x] = 1;
		p[y] = 1;
	}

	for(int i = 1; i <= n; i++)
	{
		if(!p[i])
		{
			currNode = 1;
			cout<<n - 1<<endl;
			for(int j = 0; j < n - 1; j++)
			{
				if(currNode == i) currNode++;

				cout<<i<<" "<<currNode<<endl;
				currNode++;
			}

			return 0;
		}
	}

	return 0;
}
