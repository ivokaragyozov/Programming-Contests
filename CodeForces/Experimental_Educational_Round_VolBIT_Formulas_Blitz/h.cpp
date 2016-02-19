#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	for(int i1 = n; i1 >= 1; i1--)
	{
		for(int i2 = i1 - 1; i2 >= 1; i2--)
		{
			for(int i3 = i2 - 1; i3 >= 1; i3--)
			{
				for(int i4 = i3 - 1; i4 >= 1; i4--)
				{
					for(int i5 = i4 - 1; i5 >= 1; i5--)
					{
						ans += i1 * i2 * i3 * i4 * i5;
					}
				}
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
