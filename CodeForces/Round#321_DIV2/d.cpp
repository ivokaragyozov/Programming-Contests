#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 18, maxK = maxN * (maxN - 1);

long long n, m, k, rules[maxK + 1][2], dp[262145][maxN + 1], a[maxN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m>>k;
	
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	for(int i = 0; i < k; i++)
	{
		cin>>rules[i][0]>>rules[i][1];
	}

	
}
