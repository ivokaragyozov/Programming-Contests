#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n, pascal[1000][1000];

void generate_pascal()
{
	pascal[0][0] = pascal[1][0] = pascal[1][1] = 1;

	for(int i = 2; i <= n; i++)
	{

		pascal[i][0] = pascal[i][n] = 1;
		for(int j = 1; j < n; j++)
		{
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	generate_pascal();

	cout<<pascal[n][5] + pascal[n][6] + pascal[n][7]<<endl;
	return 0;
}
