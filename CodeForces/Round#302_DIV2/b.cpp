#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 100;

int n, k, p, q;
char mapOfSea[maxN + 1][maxN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			mapOfSea[i][j] = 'S';
		}
	}

	for(int i = 0; i < k; i++)
	{
		if(p == n)
		{
			cout<<"NO"<<endl;
			return 0;
		}

		mapOfSea[p][q] = 'L';

		q += 2;
		if(q >= n)
		{
			if(p % 2 == 0) q = 1;
			else q = 0;
			p++;
		}
	}
	
	cout<<"YES"<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<<mapOfSea[i][j];
		}
		cout<<endl;
	}

	return 0;
}
