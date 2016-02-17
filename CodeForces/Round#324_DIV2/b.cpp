#include <iostream>
#define endl '\n'
using namespace std;

const long long mod = 1e9 + 7;

int n;
long long answer, sum27 = 1, sum7 = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		sum27 *= 27;
		sum27 %= mod;
		sum7 *= 7;
		sum7 %= mod;
	}

	answer = sum27 - sum7;
	if(answer < 0) answer += mod;

	cout<<answer<<endl;
	return 0;
}
