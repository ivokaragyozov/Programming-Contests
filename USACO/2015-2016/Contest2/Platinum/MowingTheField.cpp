#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

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
struct segment
{
	point a, b;

	segment(){}
	segment(point a, point b)
	{
		this->a = a;
		this->b = b;
	}
};

int n, t, x, y, lastX, lastY, ans;
vector<segment> segments;

bool ccw(point A, point B, point C)
{
	return (C.y - A.y) * (B.x - A.x) > (B.y - A.y) * (C.x - A.x);
}
bool areCrossing(segment c, segment d)
{
	point A = c.a, B = c.b, C = d.a, D = d.b;
	return (ccw(A, C, D) != ccw(B, C, D) && ccw(A, B, C) != ccw(A, B, D));
}

int main()
{
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>t;
	for(int i = 0; i < n; i++)
	{
		cin>>x>>y;

		for(int j = i - t - 1; j >= 0; j--)
		{
			if(areCrossing(segments[j], segment(point(lastX, lastY), point(x, y)))) ans++;
		}

		if(i != 0) segments.push_back(segment(point(lastX, lastY), point(x, y)));
		lastX = x;
		lastY = y;
	}

	cout<<ans<<endl;
	return 0;
}
