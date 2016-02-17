/**
Ivo Karagyozov
NOI2 2013 C2 viruses
*/
#include<iostream>
#include<queue>
using namespace std;

struct cell
{
    int i, j, br;
};

int n, m, k, maxbr=0;
bool used[3005][3005];
queue<cell> q;

void bfs()
{
	while(!q.empty())
    {
        int i=q.front().i, j=q.front().j, br=q.front().br;
        q.pop();
        if(i>0 && used[i-1][j]==0)
        {
            cell c;
            c.i=i-1; c.j=j; c.br=br+1;
            q.push(c);
            used[i-1][j]=1;
            if(br+1>maxbr)maxbr=br+1;
        }
        if(j<m-1 && used[i][j+1]==0)
        {
            cell c;
            c.i=i; c.j=j+1; c.br=br+1;
            q.push(c);
            used[i][j+1]=1;
            if(br+1>maxbr)maxbr=br+1;
        }
        if(i<n-1 && used[i+1][j]==0)
        {
            cell c;
            c.i=i+1; c.j=j; c.br=br+1;
            q.push(c);
            used[i+1][j]=1;
            if(br+1>maxbr)maxbr=br+1;
        }
        if(j>0 && used[i][j-1]==0)
        {
            cell c;
            c.i=i; c.j=j-1; c.br=br+1;
            q.push(c);
            used[i][j-1]=1;
            if(br+1>maxbr)maxbr=br+1;
        }
    }
}

int main()
{
	cin>>n>>m>>k;
	for(int i=0; i<k; i++)
	{
		cell virus;
		cin>>virus.i>>virus.j;
		virus.i--; virus.j--; virus.br=0;
		q.push(virus);
		used[virus.i][virus.j]=1;
	}
	bfs();
    cout<<maxbr<<endl;
	return 0;
}
