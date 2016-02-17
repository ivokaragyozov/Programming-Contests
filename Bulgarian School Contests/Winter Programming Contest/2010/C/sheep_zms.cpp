#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1005;

bool used[maxN];
int n, k, a[maxN], maxA, sum, le, ri, mid, ans, curr;

int solve(int capacity)
{
	int currAns = 0, currSum = 0;

	memset(used, 0, sizeof(used));
	while(1)
	{
		currSum = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			if(!used[i] && currSum + a[i] <= capacity)
			{
				currSum += a[i];
				used[i] = true;
			}
		}
		if(currSum == 0) break;
		currAns++;
	}

	return currAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];

		if(a[i] > maxA) maxA = a[i];
		sum += a[i];
	}

	sort(a, a + n);
	
	le = maxA;
	ri = sum;
	while(le <= ri)
	{
		mid = (le + ri) / 2;

		curr = solve(mid);
		if(curr > k) le = mid + 1;
		else 
		{
			ans = mid;
			ri = mid - 1;
		}
	}

	cout<<ans<<endl;
	return 0;
}
