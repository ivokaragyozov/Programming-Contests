#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 55;

bool used[maxN];
int n, a[maxN][maxN], dig[maxN], ans[maxN], currMax, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>a[i][j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		memset(dig, 0, sizeof(dig));
		for(int j = i; j < n; j++)
		{
			dig[a[j][i]]++;
			dig[a[i][j]]++;
		}
		for(int j = i - 1; j >= 0; j--)
		{
			dig[a[j][i]]++;
			dig[a[i][j]]++;
		}

		currMax = 0;
		b = 0;
		for(int j = 1; j <= n; j++)
		{
			if(dig[j] >= currMax) 
			{
				currMax = dig[j];
				b = j;
			}
		}
		ans[i + 1] = b;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!used[ans[i]])
		{
			cout<<ans[i]<<" ";
			used[ans[i]] = true;
		}
		else cout<<n<<" ";
	}
	cout<<endl;

	return 0;
}
