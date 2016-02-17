#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long maxL = 1e18, maxI = 1e9;

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
		string input = "input." + intToString(cs) + ".txt";
		FILE *OUT;
		OUT = fopen(input.c_str(), "w");

		long long x1 = rand() % maxL - maxI, x2 = rand() % maxL - maxI, y1 = rand() % maxL - maxI, y2 = rand() % maxL - maxI;
		fprintf(OUT, "%lld %lld\n%lld %lld\n", x1, y1, x2, y2);
	}

	return 0;
}
