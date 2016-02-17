#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 50;

int n, a, b;
bool row[maxN + 5], col[maxN + 5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n * n; i++)
	{
		cin>>a>>b;

		if(!row[a] && !col[b])
		{
			cout<<i + 1<<" ";
			row[a] = true;
			col[b] = true;
		}
	}

	return 0;
}
