#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 1e6;

int n, m, a[maxN + 5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	sort(a, a + n);

	cout<<a[m - 1]<<endl;
	return 0;
}
