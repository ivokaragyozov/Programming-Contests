#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	cin>>n;
	if(n % 5 == 0) cout<<n / 5<<endl;
	else cout<<n / 5 + 1<<endl;

	return 0;
}

