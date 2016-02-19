#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long double a, b, c, d, x1, x2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>a>>b>>c;
	d = b * b - 4 * a * c;

	x1 = (-b + sqrt(d)) / (2 * a);
	x2 = (-b - sqrt(d)) / (2 * a);
	
	cout<<fixed<<setprecision(7);
	cout<<max(x1, x2)<<endl<<min(x1, x2)<<endl;
	return 0;
}
