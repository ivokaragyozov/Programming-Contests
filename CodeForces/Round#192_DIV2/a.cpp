#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 10, maxM = 10;

bool col[maxN + 1][maxM + 1], row[maxN + 1][maxM + 1];
char table[maxN + 1][maxM + 1];
int n, m, answer, cntCols;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin>>table[i][j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(table[i][j] == 'S' || (i != 0 && row[i - 1][j])) row[i][j] = true;
			if(table[i][j] == 'S' || (j != 0 && col[i][j - 1])) col[i][j] = true;
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(!col[i][m - 1]) 
		{
			cntCols++;
			answer += m;
		}
	}
	for(int i = 0; i < m; i++)
	{
		if(!row[n - 1][i]) answer += n - cntCols;
	}

	cout<<answer<<endl;
	return 0;
}
