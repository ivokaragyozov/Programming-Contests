#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, row, k, matrix[505][505], aft, sum, curr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;

	aft = n - k;
	row = 1;
	for(int i = n * n - aft; ; i -= aft + 1)
	{
		sum += i;
		matrix[row++][k] = i;

		if(row == n + 1) break;
	}
	
	curr = 1;
	for(int i = n; i >= 1; i--)
	{
		for(int j = 1; j < k; j++)
		{
			matrix[i][j] = curr++;
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = k + 1; j <= n; j++)
		{
			matrix[i][j] = matrix[i][j - 1] + 1;
		}
	}
	
	cout<<sum<<endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
