#include <iostream>
#define endl '\n'
using namespace std;

int a, b, c, d, pointsM, pointsV;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>a>>b>>c>>d;

	pointsM = max((3 * a) / 10, a - a / 250 * c);
	pointsV = max((3 * b) / 10, b - b / 250 * d);

	if(pointsM == pointsV) cout<<"Tie"<<endl;
	else cout<<(pointsM < pointsV ? "Vasya" : "Misha")<<endl;

	return 0;
}
