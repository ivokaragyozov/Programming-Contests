#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n, gaus;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	
	if(n == 0) cout<<1<<endl;
	else if(n == 1) cout<<7<<endl;
	gaus = (n + 1) * n / 2;

	if(n > 1) cout<<(gaus - 1) * 6 + 7<<endl;
	return 0;
}
