#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 100;

bool passedLevels[maxN + 1];
int n, p, q, cntPassedLevels, level;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	cin>>p;
	for(int i = 0; i < p; i++)
	{
		cin>>level;

		if(!passedLevels[level])
		{
			passedLevels[level] = true;
			cntPassedLevels++;
		}
	}

	cin>>q;
	for(int i = 0; i < q; i++)
	{
		cin>>level;

		if(!passedLevels[level])
		{
			passedLevels[level] = true;
			cntPassedLevels++;
		}
	}

	cout<<(cntPassedLevels == n ? "I become the guy." : "Oh, my keyboard!")<<endl;
	return 0;
}
