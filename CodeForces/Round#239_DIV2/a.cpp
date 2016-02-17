#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;

const int maxN = 105;

int n, k[maxN], m, currTime, minTime = INT_MAX;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>k[i];
	}


	for(int i = 0; i < n; i++)
	{
		currTime = 0;

		for(int j = 0; j < k[i]; j++)
		{
			cin>>m;
			currTime += m * 5 + 15;
		}

		if(currTime < minTime) minTime = currTime;
	}
	cout<<minTime<<endl;
	return 0;
}
