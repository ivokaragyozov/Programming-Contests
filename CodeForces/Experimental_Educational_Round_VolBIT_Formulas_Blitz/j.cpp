#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n, special_number;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	special_number = 5 * 7 * 8 * 9;
	cout<<n / special_number<<endl;
	return 0;
}
