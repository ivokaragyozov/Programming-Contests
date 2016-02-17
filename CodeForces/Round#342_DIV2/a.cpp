#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n, a, b, c, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>a>>b>>c;
	
	if(n < a && n < b)
	{
		cout<<0<<endl;
		return 0;
	}

	if(a <= b - c) ans = n / a;
	else
	{
		if(b <= n) ans = (n - c) / (b - c);
		n = n - ans * b + ans * c;
		ans += n / a;
	}

	cout<<ans<<endl;
	return 0;
}
