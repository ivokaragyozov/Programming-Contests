#include <iostream>
#define endl '\n'
using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	
	cout<<(n % 2 == 0 && n != 2 ? "YES" : "NO")<<endl;
	return 0;
}
