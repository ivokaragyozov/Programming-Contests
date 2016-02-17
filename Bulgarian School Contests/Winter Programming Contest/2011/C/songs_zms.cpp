#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 50005;

int n, a, pos_ranking1[maxN], pos_ranking2[maxN], diff1, diff2, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a;
		pos_ranking1[a] = i;
	}
	for(int i = 0; i < n; i++)
	{
		cin>>a;
		pos_ranking2[a] = i;
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			diff1 = pos_ranking1[i] - pos_ranking1[j];
			diff2 = pos_ranking2[i] - pos_ranking2[j];
			if((diff1 < 0 && diff2 >= 0) || (diff1 >= 0 && diff2 < 0)) ans++; 
		}
	}

	cout<<ans<<endl;
	return 0;
}
