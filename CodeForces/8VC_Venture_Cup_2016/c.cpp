#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, curr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;

	curr = 1;
	while(1)
	{
		if(curr % 2 == 0 && curr % 3 == 0)
		{
			if(n <= m) m--;
			else n--;
		}
		else if(curr % 2 == 0)
		{
			if(n != 0) n--;
		}
		else if(curr % 3 == 0)
		{
			if(m != 0) m--;
		}
		if(n == 0 && m == 0) break;

		curr++;
	}

	cout<<curr<<endl;
	return 0;
}
