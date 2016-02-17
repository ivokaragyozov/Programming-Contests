#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 205, maxM = 205;

bool p;
char board[maxN][maxM];
int n, m, ans;

int main()
{
	freopen("fortmoo.in", "r", stdin);
	freopen("fortmoo.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin>>board[i][j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			for(int i1 = i; i1 < n; i1++)
			{
				for(int j1 = j; j1 < m; j1++)
				{
					p = true;
					for(int k = i; k <= i1; k++)
					{
						if(board[k][j] == 'X' || board[k][j1] == 'X')
						{
							p = false;
							break;
						}
					}

					for(int k = j; k <= j1; k++)
					{
						if(board[i][k] == 'X' || board[i1][k] == 'X')
						{
							p = false;
							break;
						}
					}

					if(p)
					{
						if((j1 - j + 1) * (i1 - i + 1) > ans) ans = (j1 - j + 1) * (i1 - i + 1);
					}
				}
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}
