#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

double d, l, v1, v2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>d>>l>>v1>>v2;

	double posLeft = (l - d) * (v1 / (v1 + v2)), posRight = posLeft + d;

	double dist1 = posLeft, dist2 = l - posRight;
	
	cout<<fixed<<setprecision(7);
	cout<<max(dist1 / v1, dist2 / v2)<<endl;
	return 0;
}

