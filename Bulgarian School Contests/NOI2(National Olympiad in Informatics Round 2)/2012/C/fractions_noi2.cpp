#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

unsigned long long n, lastA = 1LL, lastB = 1LL;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(long long i = 2; i <= n; i++)
	{
		lastA = i * lastA + lastB;
		lastB *= i;

		for(long long j = 2; j <= n; j++)
		{
			if(lastA % j == 0 && lastB % j == 0)
			{
				lastA /= j;
				lastB /= j;
			}
		}
	}

	cout<<lastA / lastB<<" "<<lastA % lastB<<" "<<lastB<<endl;
	return 0;
}
