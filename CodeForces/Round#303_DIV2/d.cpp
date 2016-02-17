#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

int n, times[maxN + 1], answer = 1, curTime;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>times[i];
	}

	sort(times, times + n);

	curTime = times[0];
	for(int i = 1; i < n; i++)
	{
		if(times[i] >= curTime)
		{
			curTime += times[i];
			answer++;
		}
	}

	cout<<answer<<endl;
	return 0;
}
