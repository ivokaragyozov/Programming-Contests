#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int maxN = 3000;

int n, rightTime[maxN + 1], leftTime[maxN + 1], cnt;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(rightTime, -1, sizeof(rightTime));
	memset(leftTime, -1, sizeof(leftTime));
	
	cin>>n>>s;
	
	for(int le = 0; le < n; le++)
	{
		if(s[le] == 'L') leftTime[le] = 0;
		else
		{
			if(le != 0 && leftTime[le - 1] != -1) leftTime[le] = leftTime[le - 1] + 1;
		}
	}
	for(int ri = n - 1; ri >= 0; ri--)
	{
		if(s[ri] == 'R') rightTime[ri] = 0;
		else
		{
			if(ri != 0 && rightTime[ri + 1] != -1) rightTime[ri] = rightTime[ri + 1] + 1;
		}

		if(rightTime[ri] < leftTime[ri])
		{
			leftTime[ri] = -1;
		}
		else
		{
			rightTime[ri] = -1;
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(leftTime[i] == rightTime[i])
		{
			cout<<i<<endl;
			cnt++;
		}
	}

	cout<<cnt<<endl;
	return 0;
}
