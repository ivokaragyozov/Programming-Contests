#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

long long n, a[maxN + 1], dp[maxN + 1], currMax;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	for(int i = n - 1; i >= 0; i--)
	{
		dp[i] = currMax;
		
		if(a[i] > currMax || n - 1 == 0) currMax = a[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(i != n - 1)
		{
			if(a[i] <= dp[i]) cout<<dp[i] - a[i] + 1<<" ";
			else cout<<0<<" ";
		}
		else
		{
			cout<<0<<endl;
		}
	}

	return 0;
 }
