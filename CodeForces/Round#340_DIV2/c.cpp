#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 2005;

long long n, x1, y3, x2, y2, xf[maxN], yf[maxN], r1, r2, d1, d2;

long long dist(long long x, long long y, long long xx, long long yy)
{
	return (x - xx) * (x - xx) + (y - yy) * (y - yy);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>x1>>y3>>x2>>y2;
	for(int i = 0; i < n; i++)
	{
		cin>>xf[i]>>yf[i];
		d1 = dist(x1, y3, xf[i], yf[i]);
		d2 = dist(x2, y2, xf[i], yf[i]);

		if(d1 <= r1 || d2 <= r2) continue;
		
		if(d1 < d2)
		{
			r1 = d1;
			r2 = 0;
			for(int j = 0; j < i; j++)
			{
				if(dist(x1, y3, xf[j], yf[j]) > r1 && dist(x2, y2, xf[j], yf[j]) > r2) r2 = dist(x2, y2, xf[j], yf[j]);
			}
		}
		else
		{
			r1 = 0;
			r2 = d2;
			for(int j = 0; j < i; j++)
			{
				if(dist(x2, y2, xf[j], yf[j]) > r2 && dist(x1, y3, xf[j], yf[j]) > r1) r1 = dist(x1, y3, xf[j], yf[j]);
			}
		}
	}

	cout<<r1 + r2<<endl;
}
