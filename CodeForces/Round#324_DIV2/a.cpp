#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int n;
string t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>t;
	while(t.size() < n)
	{
		t += '0';
	}

	if(t.size() == n) cout<<t<<endl;
	else cout<<-1<<endl;
	return 0;
}
