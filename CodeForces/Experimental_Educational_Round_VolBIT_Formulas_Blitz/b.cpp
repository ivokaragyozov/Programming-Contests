#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;
	cout<<fixed<<setprecision(7);
	cout<<n * pow(1.000000011, k)<<endl;
	return 0;
}
