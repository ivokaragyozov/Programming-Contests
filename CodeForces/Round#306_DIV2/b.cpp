#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;

const int maxN = 15;

int n, l, r, x, c[maxN + 1], answer;

int solve(int pos, int sum, int curMax, int curMin)
{
	int curAnswer = 0;
 
	if(sum > r) return 0;
	
	if(sum >= l && curMax - curMin >= x) 
	{
		curAnswer++;
	}
	for(int i = pos + 1; i < n; i++)
	{
		curAnswer += solve(i, sum + c[i], max(curMax, c[i]), min(curMin, c[i]));
	}

	return curAnswer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>l>>r>>x;

	for(int i = 0; i < n; i++)
	{
		cin>>c[i];
	}

	for(int i = 0; i < n; i++)
	{
		answer += solve(i, c[i], c[i], c[i]);
	}

	cout<<answer<<endl;
	return 0;
}
