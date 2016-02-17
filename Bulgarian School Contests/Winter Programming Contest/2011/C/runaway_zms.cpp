#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1005;

int n, board[maxN][maxN], curr_distance, k, query;
map<int, int> min_distance;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int j = 0; j < n; j++)
	{
		for(int i = n - 1; i >= 0; i--)
		{
			cin>>board[i][j];
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			curr_distance = i + j;
			if(min_distance.find(board[i][j]) == min_distance.end() || min_distance[board[i][j]] > curr_distance)
			{
				min_distance[board[i][j]] = curr_distance;
			}
		}
	}
	
	cin>>k;
	for(int i = 0; i < k; i++)
	{
		cin>>query;
		
		if(min_distance.find(query) == min_distance.end()) cout<<"No Solution"<<endl;
		else cout<<min_distance[query]<<endl;
	}

	return 0;
}
