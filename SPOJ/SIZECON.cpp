#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, a, sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a;

		if(a > 0) sum += a;
	}

	cout<<sum<<endl;
	return 0;
}
