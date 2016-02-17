#include <iostream>
#define endl '\n'
using namespace std;

int a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>a>>b;
	if(a > b) swap(a, b);

	cout<<a<<" ";
	b -= a;
	a = 0;
	cout<<b / 2<<endl;
	return 0;
}
