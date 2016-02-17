#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long solve(long long x1, long long y1, long long x2, long long y2, FILE *OUT)
{
	long long d1, d2;
	d1=abs(x1-x2);
	d2=abs(y1-y2);
	fprintf(OUT, "%lld\n", max(d1,d2));
}
string intToString(int n)
{
	string s;
	
	while(n > 0)
	{
		s = (char)(n % 10 + '0') + s;
		n /= 10;
	}

	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int cs = 1; cs <= 100; cs++)
	{
		string input = "input." + intToString(cs) + ".txt", output = "output." + intToString(cs) + ".txt";

		FILE *IN, *OUT;
		IN = fopen(input.c_str(), "r");
		OUT = fopen(output.c_str(), "w");

		long long x1, x2, y1, y2;
		fscanf(IN, "%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

		solve(x1, y1, x2, y2, OUT);
	}

	return 0;
}
