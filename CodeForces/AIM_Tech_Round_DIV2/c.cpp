#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool matrix[505][505];
char arr[505];
int n, m, u, v, cnt, cntA, cntC, cntA1, cntC1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i = 0; i < m; i++)
	{
		cin>>u>>v;

		matrix[u][v] = true;
		matrix[v][u] = true;
	}
	
	for(int i = 1; i <= n; i++)
	{
		cnt = 0;
		cntA = 0;
		cntC = 0;
		cntA1 = 0;
		cntC1 = 0;
		for(int j = 1; j <= n; j++)
		{
			if(i == j) continue;

			if(matrix[i][j])
			{
				cnt++;

				if(j < i)
				{
					if(arr[j] == 'a') cntA++;
					else if(arr[j] == 'c') cntC++;
				}
			}
			else
			{
				if(j < i)
				{
					if(arr[j] == 'a') cntA1++;
					else cntC1++;
				}
			}
		}
	
		if(cnt == n - 1) arr[i] = 'b';
		else
		{
			if(cntA != 0) arr[i] = 'a';
			else if(cntC != 0) arr[i] = 'c';
			else
			{
				if(cntA1 == 0 && cntC1 == 0) arr[i] = 'a';
				else if(cntA1 != 0) arr[i] = 'c';
				else arr[i] = 'a';
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if((arr[i] == 'a' && arr[j] == 'c') || (arr[i] == 'c' && arr[j] == 'a'))
			{
				if(matrix[i][j])
				{
					cout<<"No"<<endl;
					return 0;
				}
			}
			else
			{
				if(!matrix[i][j])
				{
					cout<<"No"<<endl;
					return 0;
				}
			}
		}
	}


	cout<<"Yes"<<endl;
	for(int i = 1; i <= n; i++)
	{
		cout<<arr[i];
	}
	cout<<endl;

	return 0;
}
