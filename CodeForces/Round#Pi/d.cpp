#include <iostream>
#include <set>
#define endl '\n'
using namespace std;

const int maxN = 2*1e5+1;

struct interval
{
	int le, ri;

	interval() = default;

	interval(int l, int r): le(l), ri(r) {}
};

int n, k, a, m, x[maxN], curr, answer = -1;
set<interval> intervals; 

bool operator< (interval a, interval b)
{
	return a.le < b.le;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k>>a>>m;
	
	intervals.insert(interval(0, n-1));
	
	set<interval>::iterator it;
	int le = 0, ri = n-1;
	curr = (ri-le+2)/(a+1);

	for(int i = 0; i < m; i++)
	{

		cin>>x[i];
		x[i]--;
		
		if(answer != -1) continue;

		it = intervals.upper_bound(interval(x[i], x[i]+1));
		it--;

		le = it->le;
		ri = it->ri;

		//cout<<i<<" "<<le<<" "<<ri<<"     "<<le<<" "<<x[i]<<"     "<<x[i]+1<<" "<<ri<<endl;

		intervals.erase(it);
		if(x[i] != le) intervals.insert(interval(le, x[i]-1));
		if(x[i] != ri) intervals.insert(interval(x[i]+1, ri));

		curr -= (ri-le+2)/(a+1);
		//cout<<curr<<endl;
		curr += (x[i]-1-le+2)/(a+1) + (ri-x[i]-1+2)/(a+1);
		//cout<<curr<<endl;
		
		if(curr < k) answer = i + 1;
	}

	cout<<answer<<endl;
	return 0;
}

