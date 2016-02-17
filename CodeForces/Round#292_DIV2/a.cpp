#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

long long a, b, s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>a>>b>>s;
	
	a = abs(a);
	b = abs(b);

	if(a + b <= s && (s - (a + b)) % 2 == 0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}
