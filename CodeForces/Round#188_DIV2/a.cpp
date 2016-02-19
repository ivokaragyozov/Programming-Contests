#include <bits/stdc++.h>
#define endl '\n'
using namespace std; 

long long n, k, cnt_odd;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;

	if(n % 2 == 0) cnt_odd = n / 2;
	else cnt_odd = n / 2 + 1;

	if(k > cnt_odd)
	{
		k -= cnt_odd;
		cout<<2 * k<<endl;
	}
	else cout<<2 * k - 1<<endl;

	return 0;
}
