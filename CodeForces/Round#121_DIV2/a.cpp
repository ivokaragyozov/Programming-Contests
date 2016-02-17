#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long maxN = 1e9 + 5;

long long n;
map<long long, bool> numbers;

void generate()
{
	for(int i = 1; i <= sqrt(maxN); i++)
	{
		numbers[(i * (i + 1)) / 2] = 1;		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	generate();
	cin>>n;
	
	map<long long, bool>::iterator it;
	for(it = numbers.begin(); it != numbers.end(); it++)
	{
		if((*it).second != 1) continue;
		if(n - (*it).first < 0) break;

		if(numbers[n - (*it).first] == 1)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}

	cout<<"NO"<<endl;
	return 0;
}
