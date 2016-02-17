#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 5;

int t, n, a[2 * maxN], currSum, ans;
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(1)
	{
		ans = 0;
		currSum = 0;

		cin>>n;
		
		if(n == 0) break;
			
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
			a[i + n] = a[i];
		}

		for(int i = 0; i < 2 * n - 1; i++)
		{
			currSum += a[i];
			q.push(a[i]);
			
			if(currSum < 0)
			{
				while(currSum < 0 && !q.empty())
				{
					currSum -= q.front();
					q.pop();
				}
			}

			if(q.size() == n) 
			{
				ans++;
				cout<<"        "<<i - n<<" "<<ans<<endl;
				currSum -= q.front();
				q.pop();
			}
		}

		while(!q.empty()) q.pop();

		cout<<ans<<endl;
	}

	return 0;
}
