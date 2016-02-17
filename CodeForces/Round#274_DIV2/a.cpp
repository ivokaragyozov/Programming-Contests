#include <iostream>
#define endl '\n'
using namespace std;

int a, b, c, val1, val2, val3, val4, val5, val6;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>a>>b>>c;

	val1 = a + b + c;
	val2 = a + b * c;
	val3 = a * b + c;
	val4 = a * b * c;
	val5 = (a + b) * c;
	val6 = a * (c + b);

	cout<<max(val1, max(val2, max(val3, max(val4, max(val5, val6)))))<<endl;
	return 0;
}
