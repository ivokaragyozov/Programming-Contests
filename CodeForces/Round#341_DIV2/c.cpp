#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

unsigned long long n, p, le, ri, cnt[maxN], cnt1[maxN], start;
double ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>p;
	for(int i = 0; i < n; i++)
	{
		cin>>le>>ri;

		if(le % p == 0) start = le;
		else start = (le / p + 1) * p;
		
		if(start <= ri) cnt[i + 1] = (ri - start) / p + 1;
		else cnt[i + 1] = 0;
		cnt1[i + 1] = ri - le + 1;
	}

	cnt[0] = cnt[n];
	cnt1[0] = cnt1[n];

	if(n == 2) n--;
	for(int i = 1; i <= n; i++)
	{
		ans += ((double)(cnt[i] * cnt1[i - 1] + cnt1[i] * cnt[i - 1] - cnt[i] * cnt[i - 1]) * 2000) / (cnt1[i] * cnt1[i - 1]);
	}
	
	cout<<fixed<<setprecision(7);
	cout<<ans<<endl;
	return 0;
}
