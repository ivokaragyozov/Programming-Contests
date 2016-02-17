#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int xa, ya;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>xa>>ya;

	if(xa >= 0) cout<<0<<" "<<abs(xa) + abs(ya)<<" "<<abs(xa) + abs(ya)<<" "<<0<<endl;
	else cout<<abs(xa) + abs(ya)<<" "<<0<<" "<<0<<" "<<abs(xa) + abs(ya)<<endl;
	
	return 0;
}
