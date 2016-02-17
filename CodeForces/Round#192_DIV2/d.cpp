#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

const int maxN = 1000, maxM = 1000;

struct point
{
	int x, y;

	point(){}
	point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

bool vis[maxN + 1][maxM + 1];
char table[maxN + 1][maxM + 1];
int n, m, needTime[maxN + 1][maxM + 1], myTime, cnt, answer;
point exitLocation, currPoint;
queue<point> q;
queue<int> t;

void bfs(point start)
{
	int x, y, time;

	q.push(start);
	t.push(0);

	while(!q.empty())
	{
		currPoint = q.front();
		time = t.front();
		q.pop();
		t.pop();

		x = currPoint.x;
		y = currPoint.y;

		needTime[x][y] = time;
		if(table[x][y] == 'S') myTime = time;
		
		if(x != 0 && !vis[x - 1][y] && table[x - 1][y] != 'T')
		{
			q.push(point(x - 1, y));
			t.push(time + 1);
			vis[x - 1][y] = true;
		}
		if(y != m - 1 && !vis[x][y + 1] && table[x][y + 1] != 'T')
		{
			q.push(point(x, y + 1));
			t.push(time + 1);
			vis[x][y + 1] = true;
		}
		if(x != n - 1 && !vis[x + 1][y] && table[x + 1][y] != 'T')
		{
			q.push(point(x + 1, y));
			t.push(time + 1);
			vis[x + 1][y] = true;
		}
		if(y != 0 && !vis[x][y - 1] && table[x][y - 1] != 'T') 
		{
			q.push(point(x, y - 1));
			t.push(time + 1);
			vis[x][y - 1] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin>>table[i][j];

			if(table[i][j] == 'E') exitLocation = point(i, j);
		}
	}
	bfs(exitLocation);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(table[i][j] >= '0' && table[i][j] <= '9')
			{
				cnt = table[i][j] - '0';

				if(needTime[i][j] <= myTime && needTime[i][j] != 0) answer += cnt;
			}
		}
	}

	cout<<answer<<endl;
	return 0;
}
