#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 3e4 + 5;

int n, t, a[maxN], current_pos;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>t;
	for(int i = 1; i < n; i++)
	{
		cin>>a[i];
	}

	current_pos = 1;
	while(current_pos <= t)
	{
		if(current_pos == t)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		
		current_pos += a[current_pos];
	}

	cout<<"NO"<<endl;
	return 0;
}
