#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int t, a, squares[500], indSquare, ans[1005];

void generateSquares()
{
	for(int i = 1; i <= sqrt(1000); i++)
	{
		squares[indSquare++] = i * i;
	}
}
void generateAns()
{
	for(int i = 0; i < 1005; i++) ans[i] = INT_MAX;

	ans[0] = 0;
	for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < indSquare; j++)
		{
			if(i + squares[j] > 1000) break;
			ans[i + squares[j]] = min(ans[i] + 1, ans[i + squares[j]]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	generateSquares();
	generateAns();
	
	cin>>t;
	for(int cs = 1; cs <= t; cs++)
	{
		cin>>a;
		cout<<ans[a]<<endl;
	}
}
