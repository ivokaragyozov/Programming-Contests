#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

bool p;
int n, k, a[maxN], ans = INT_MAX;

bool cmp(int x, int y)
{
	return x > y;
}
void solve(int curr, int currCnt)
{
	
	if(curr < 0) return;
	else if(curr == 0)
	{
		if(currCnt < ans) ans = currCnt;
		return;
	}

	for(int i = 0; i < k; i++)
	{
		solve(curr - a[i], currCnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;
	for(int i = 0; i < k; i++) 
	{
		cin>>a[i];
	}

	sort(a, a + k, cmp);

	solve(n, 0);
	cout<<ans<<endl;
	return 0;
}
