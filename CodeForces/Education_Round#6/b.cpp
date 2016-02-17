#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a, b, ans, digs[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>a>>b;
	for(int i = a; i <= b; i++)
	{
		int j = i;
		while(j > 0)
		{
			ans += digs[j % 10];
			j /= 10;
		}
	}

	cout<<ans<<endl;
	return 0;
}
