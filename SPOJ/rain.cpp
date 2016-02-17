#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

long long cntCases, n, m, s, t, a, currSum, currCnt, maxCnt;
queue<long long> q;

void init()
{
	currSum = 0;
	currCnt = 0;
	maxCnt = 0;
	while(!q.empty()) q.pop();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>cntCases;
	for(int cs = 0; cs < cntCases; cs++)
	{
		init();
		cin>>s>>t>>n>>m;

		maxCnt = n;

		s = (78901 + 31 * s) % 699037;
		t = (23456 + 64 * t) % 2097151;
		for(int i = 1; i <= n; i++)
		{
			a = (s % 100 + 1) * (t % 100 + 1);

			currSum += a;
			currCnt++;
			q.push(a);

			if(currSum > m)
			{
				while(currSum > m)
				{
					if(currCnt - 1 < maxCnt) maxCnt = currCnt - 1;
					currSum -= q.front();
					currCnt--;
					q.pop();
				}
			}
			
			s = (78901 + 31 * s) % 699037;
			t = (23456 + 64 * t) % 2097151;
		}

		cout<<maxCnt<<endl;
	}

	return 0;
}
