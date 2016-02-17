/**
Ivo Karagyozov
NOI3 2015 C4 cover
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 10005;

int n, a, numbers[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a;

		numbers[i] += a;
		for(int j = i - a - 1; j >= 0; j--)
		{
			numbers[j]++;
		}
	}

	for(int i = 0; i < n; i++)
	{
		cout<<numbers[i] + 1<<endl;
	}

	return 0;
}
