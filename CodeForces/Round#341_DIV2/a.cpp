#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

long long n, a, indO, odds[maxN], sum, sumO;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a;

		if(a % 2 == 0) sum += a;
		else 
		{
			odds[indO++] = a;
			sumO += a;
		}
	}

	sort(odds, odds + indO);

	if(indO % 2 == 0) sum += sumO;
	else sum += sumO - odds[0];
	
	cout<<sum<<endl;
	return 0;
}
