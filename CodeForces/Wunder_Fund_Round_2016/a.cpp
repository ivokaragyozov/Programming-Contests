#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

int n, v[maxN], currInd;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		v[currInd] = 1;
		for(int j = currInd - 1; j >= 0; j--)
		{
			if(v[j] == v[j + 1])
			{
				currInd--;
				v[j] = v[j] + 1;
			}
			else break;
		}
		currInd++;
	}

	for(int i = 0; i < currInd; i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

	return 0;
}
