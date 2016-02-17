#include <iostream>
#include <map>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 1e5;

int n, a[maxN + 1], b[maxN + 1], c[maxN + 1], firstMistake, secondMistake;
map<int, bool> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for(int i = 0; i < n - 1; i++)
	{
		cin>>b[i];
	}
	for(int i = 0; i < n - 2; i++)
	{
		cin>>c[i];
		m[c[i]] = true;
	}

	sort(a, a + n);
	sort(b, b + n - 1);
	sort(c, c + n - 2);

	for(int i = 0; i < n; i++)
	{
		if(i == n - 1 || a[i] != b[i])
		{
			cout<<a[i]<<endl;
			break;
		}
	}
	for(int i = 0; i < n - 1; i++)
	{
		if(i == n - 2 || b[i] != c[i])
		{
			cout<<b[i]<<endl;
			break;
		}
	}

	return 0;

	cout<<firstMistake<<endl<<secondMistake<<endl;
	return 0;
}
