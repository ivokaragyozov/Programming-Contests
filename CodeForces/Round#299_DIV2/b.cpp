#include <iostream>
#define endl '\n'
using namespace std;

int n, pows[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512}, p = 9, q = 1, cntDigs = 1, answer;

bool isLucky(int a)
{
	while(a > 0)
	{
		if(a % 10 != 4 && a % 10 != 7) return false;
		a /= 10;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	while(p < n)
	{
		answer += pows[cntDigs++];
		p = p * 10 + 9;
		q = q * 10;
	}

	for(int i = q; i <= n; i++)
	{
		if(isLucky(i)) answer++;
	}

	cout<<answer<<endl;
	return 0;
}
