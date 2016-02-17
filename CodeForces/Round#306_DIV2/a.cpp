#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int findAB, findABr, findBA, findBAr;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>s;

	findAB = s.find("AB");
	findABr = s.rfind("AB");
	findBA = s.find("BA");
	findBAr = s.rfind("BA");
	
	if(findAB == string::npos || findBA == string::npos)
	{
		cout<<"NO"<<endl;
		return 0;
	}

	if(abs(findAB - findBA) >= 2 || abs(findAB - findBAr) >= 2 || abs(findABr - findBA) >= 2 || abs(findABr - findABr) >= 2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
