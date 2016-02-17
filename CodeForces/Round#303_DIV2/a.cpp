#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 100;

bool hasTurned;
int n, a, goods[maxN + 1], cntGood;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	for(int i = 0; i < n; i++)
	{
		hasTurned = false;

		for(int j = 0; j < n; j++)
		{
			cin>>a;

			if(a == 1 || a == 3) hasTurned = true;
		}

		if(!hasTurned)
		{
			goods[cntGood] = i + 1;
			cntGood++;
		}
	}

	cout<<cntGood<<endl;

	for(int i = 0; i < cntGood; i++)
	{
		cout<<goods[i];

		if(i == cntGood - 1) cout<<endl;
		else cout<<" ";
	}

	return 0;
}
