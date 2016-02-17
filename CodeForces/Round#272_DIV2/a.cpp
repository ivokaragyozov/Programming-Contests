#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;

int n, m, y, minCnt = INT_MAX;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;

	for(int x = 0; x <= n / 2; x++)
	{
		y = n - 2 * x;

		if((x + y) % m == 0)
		{
			minCnt = x + y;
		}
	}

	cout<<(minCnt == INT_MAX ? -1 : minCnt)<<endl;
	return 0;
}
