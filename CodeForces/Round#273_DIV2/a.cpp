#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int c1, c2, c3, c4, c5, sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>c1>>c2>>c3>>c4>>c5;
	sum = c1 + c2 + c3 + c4 + c5;

	if(sum % 5 == 0  && sum != 0) cout<<sum / 5<<endl;
	else cout<<-1<<endl;
	return 0;
}
