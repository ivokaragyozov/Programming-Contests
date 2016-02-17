/**
	Ivo Karagyozov
	NOI1 2014 C2 viruses
*/ 
#include<iostream>
using namespace std;
int n, m, k, board[101][101], br=0;
void dfs(int i, int j)
{
	board[i][j]=1;
	if(i<n && board[i+1][j]==0)dfs(i+1, j);
	if(j>1 && board[i][j-1]==0)dfs(i, j-1);
	if(i>1 && board[i-1][j]==0)dfs(i-1, j);
	if(j<m && board[i][j+1]==0)dfs(i, j+1);
}
int main()
{
	cin>>n>>m>>k;
	for(int i=0; i<k; i++)
	{
		int a, b;
		cin>>a>>b;
		board[a][b]=1;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(board[i][j]==0)
		 	{
				br++;
				dfs(i, j);
			}
		}
	}
	cout<<br<<endl;
	return 0;
}
