#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

long long n, x[maxN], y[maxN], number1, number2, number3;

long long det(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}
bool isInside(long long i)
{
	long long xp = x[i], yp = y[i], x1 = x[number1], y1 = y[number1], x2 = x[number2], y2 = y[number2], x3 = x[number3], y3 = y[number3];
	bool b1, b2, b3;
	
	b1 = det(xp, yp, x1, y1, x2, y2) < 0;
	b2 = det(xp, yp, x1, y1, x3, y3) < 0;
	b3 = det(xp, yp, x2, y2, x3, y3) < 0;

	return ((b1 == b2) && (b2 == b3));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>x[i]>>y[i];
	}

	number1 = 0;
	number2 = 1;
	for(int i = 2; i < n; i++)
	{
		if(det(x[i], y[i], x[0], y[0], x[1], y[1]) != 0)
		{
			number3 = i;
			break;
		}
	}
	
	if(det(x[0], y[0], x[1], y[1], x[number3], y[number3]) < 0) swap(number2, number3);
	for(int i = 2; i < n; i++)
	{
		if(i == number3) continue;
		
		long long det1 = det(x[number1], y[number1], x[number2], y[number2], x[i], y[i]), det2 = det(x[number2], y[number2], x[number3], y[number3], x[i], y[i]), det3 = det(x[number3], y[number3], x[number1], y[number1], x[i], y[i]);
		if(det1 >= 0 && det2 >= 0 && det3 >= 0)
		{
			if(det1 != 0) number3 = i;
			else if(det2 != 0) number1 = i;
			else if(det3 != 0) number2 = i;
		}
	}

	cout<<number1 + 1<<" "<<number2 + 1<<" "<<number3 + 1<<endl;
	return 0;
}
