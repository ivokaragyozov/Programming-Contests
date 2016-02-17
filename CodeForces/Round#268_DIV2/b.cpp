#include <iostream>
#define endl '\n'
using namespace std;

const int maxIntervals = 50;

int p, q, l, r, zShedule[maxIntervals + 1], xShedule[maxIntervals + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>p>>q>>l>>r;
	for(int i = 0; i < p; i++)
	{
		cin>>zShedule[i];
	}
	for(int i = 0; i < q; i++)
	{
		cin>>xShedule[i];
	}


}
