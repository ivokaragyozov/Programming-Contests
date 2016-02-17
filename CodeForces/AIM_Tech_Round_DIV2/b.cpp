#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n, a, ans;
map<int, bool> used;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a;

		while(1)
		{
			if(a == 0) break;
			if(used.find(a) == used.end())
			{
				used[a] = true;
				ans += a;
				break;
			}

			a--;
		}
	}

	cout<<ans<<endl;
	return 0;
}
