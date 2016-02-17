#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

long long n, a[maxN], indStart, ans = 1, currCnt, startInd;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	startInd = -1;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		if(a[i] == 1 && startInd == -1) startInd = i;
	}


	if(startInd == -1) 
	{
		cout<<0<<endl;
		return 0;
	}

	for(int i = startInd + 1; i < n; i++)
	{
		currCnt = 0;
		while(a[i] == 0)
		{
			currCnt++;
			i++;
		}
		
		if(i < n) ans *= (currCnt + 1);
	}

	cout<<ans<<endl;
	return 0;
}
