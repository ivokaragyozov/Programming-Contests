#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

int n, a[maxN + 1], currCnt, maxCnt = 1;
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];

		if(i == 0 || a[i] < a[i - 1])
		{
			currCnt = 1;
		}
		else
		{
			currCnt++;
			if(currCnt > maxCnt) maxCnt = currCnt;
		}
	}

	cout<<maxCnt<<endl;
	return 0;
}
