#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, x, y, z, sum_x, sum_y, sum_z;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>x>>y>>z;

		sum_x += x;
		sum_y += y;
		sum_z += z;
	}

	if(sum_x == 0 && sum_y == 0 && sum_z == 0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
