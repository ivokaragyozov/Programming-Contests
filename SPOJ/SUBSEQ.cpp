#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int t, n, a, currSum, ans;
queue<int> subseq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;
	for(int cs = 1; cs <= t; cs++)
	{
		while(!subseq.empty()) subseq.pop();
		currSum = 0;
		ans = 0;
		
		cin>>n;
		for(int i = 0; i < n; i++)
		{
			cin>>a;

			currSum += a;
			subseq.push(a);
			if(currSum > 47)
			{
				while(!subseq.empty() && currSum > 47)
				{
					currSum -= subseq.front();
					subseq.pop();
				}
			}

			if(currSum == 47) ans++;
		}

		cout<<ans<<endl;
	}

	return 0;
}
