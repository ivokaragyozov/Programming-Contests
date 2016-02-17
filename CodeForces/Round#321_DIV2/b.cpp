#include <iostream>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

struct fri
{
	int money, factor;
};

long long n, d, money, factor, currFactor, maxFactor, moneyOfFirst;
fri friends[maxN + 1];
queue<int> q;

bool cmp(fri a, fri b)
{
	return a.money < b.money;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>d;
	for(int i = 0; i < n; i++)
	{
		cin>>money>>factor;

		friends[i].money = money;
		friends[i].factor = factor;
	}

	sort(friends, friends + n, cmp);

	for(int i = 0; i < n; i++)
	{
		money = friends[i].money;
		factor = friends[i].factor;
	    

		if(i == 0) moneyOfFirst = money;
		if(money - moneyOfFirst < d)
		{
			q.push(i);
			currFactor += factor;

			if(currFactor > maxFactor) maxFactor = currFactor;
		}
		else
		{
			while(!q.empty() && money - moneyOfFirst >=  d)
			{
				currFactor -= friends[q.front()].factor;
				q.pop();
				if(!q.empty()) moneyOfFirst = friends[q.front()].money;
			}
			q.push(i);
			currFactor += factor;
			moneyOfFirst = friends[q.front()].money;

			if(currFactor > maxFactor) maxFactor = currFactor;
		}
	}

	cout<<maxFactor<<endl;
	return 0;
}	
