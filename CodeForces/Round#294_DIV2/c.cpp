#include <iostream>
#define endl '\n'
using namespace std;

int n, m, answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	
	while(n > 0 && m > 0)
	{
		if(n + m < 3) break;

		if(n >= m)
		{
			n -= 2;
			m--;
		}
		else
		{
			n--;
			m -= 2;
		}
		answer++;
	}

	cout<<answer<<endl;
	return 0;
}
