#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;

const int maxN = 100, maxK = 1000;

int n, m, a[maxN + 1], minA = INT_MAX, maxA, indOfMin, indOfMax, answer = INT_MAX, moves[maxK + 1][2], indOfMove, endInd;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];

		if(a[i] < minA)
		{
			minA = a[i];
			indOfMin = i;
		}
		if(a[i] > maxA)
		{
			maxA = a[i];
			indOfMax = i;
		}
	}

	for(int i = 0; i <= m; i++)
	{	
		if(answer > maxA - minA)
		{
			answer = maxA - minA;
			endInd = indOfMove;
		}

		a[indOfMax]--;
		a[indOfMin]++;
		moves[indOfMove][0] = indOfMax;
		moves[indOfMove++][1] = indOfMin;
		
		minA = INT_MAX;
		maxA = 0;
		for(int j = 0; j < n; j++)
		{
			if(a[j] > maxA)
			{
				maxA = a[j];
				indOfMax = j;
			}
			if(a[j] < minA)
			{
				minA = a[j];
				indOfMin = j;
			}
		}
	}

	cout<<answer<<" "<<endInd<<endl;
	for(int i = 0; i < endInd; i++)
	{
		cout<<moves[i][0] + 1<<" "<<moves[i][1] + 1<<endl;
	}

	return 0;
}
