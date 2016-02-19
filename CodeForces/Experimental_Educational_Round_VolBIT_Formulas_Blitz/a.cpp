#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	if(n == 0) cout<<1<<endl;
	else if(n == 1) cout<<5<<endl;
	else cout<<25<<endl;

	return 0;
}
