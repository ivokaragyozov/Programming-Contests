#include <iostream>
#include <queue>
#include <climits>
#define endl '\n'
using namespace std;

const int maxN = 1e5, maxK = 1e7;

struct skill
{
	int heigh, needTo10;

	skill(){}
	skill(int heigh, int needTo10)
	{
		this->heigh = heigh;
		this->needTo10 = needTo10;
	}
};

int n, k, a, b, answer;
priority_queue<skill> pq;

bool operator<(skill x, skill y)
{
	return x.needTo10 > y.needTo10;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;
	for(int i = 0; i < n; i++)
	{
		cin>>a;
		if(a != 100) pq.push(skill(a, 10 - a % 10));
		else pq.push(skill(a, maxK + 100));
	}

	while(1)
	{
		a = pq.top().needTo10;
		b = pq.top().heigh;

		if(a > k) break;
		pq.pop();
		k -= a;
		if(b + a < 100) pq.push(skill(b + a, 10));
		else if(b + a == 100) pq.push(skill(b + a, maxK + 100));
	}

	for(int i = 0; i < n; i++)
	{
		answer += pq.top().heigh / 10;
		pq.pop();
	}

	cout<<answer<<endl;
	return 0;
}
