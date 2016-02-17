#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string expression;
long double x, y, z, a, maxAns;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>x>>y>>z;	

	a = pow(x, pow(y, z));
	if(a > maxAns)
	{
		expression = "x^y^z";
		maxAns = a;
	}
	
	a = pow(x, pow(z, y));
	if(a > maxAns)
	{
		expression = "x^z^y";
		maxAns = a;
	}

	a = pow(pow(x, y), z);
	if(a > maxAns)
	{
		expression = "(x^y)^z";
		maxAns = a;
	}

	a = pow(pow(x, z), y);
	if(a > maxAns)
	{
		expression = "(x^z)^y";
		maxAns = a;
	}

	a = pow(y, pow(x, z));
	if(a > maxAns)
	{
		expression = "y^x^z";
		maxAns = a;
	}

	a = pow(y, pow(z, x));
	if(a > maxAns)
	{
		expression = "y^z^x";
		maxAns = a;
	}

	a = pow(pow(y, x), z);
	if(a > maxAns)
	{
		expression = "(y^x)^z";
		maxAns = a;
	}

	a = pow(pow(y, z), x);
	if(a > maxAns)
	{
		expression = "(y^z)^x";
		maxAns = a;
	}

	a = pow(z, pow(x, y));
	if(a > maxAns)
	{
		expression = "z^x^y";
		maxAns = a;
	}

	a = pow(z, pow(y, x));
	if(a > maxAns)
	{
		expression = "z^y^x";
		maxAns = a;
	}

	a = pow(pow(z, x), y);
	if(a > maxAns)
	{
		expression = "(z^x)^y";
		maxAns = a;
	}

	a = pow(pow(z, y), x);
	if(a > maxAns)
	{
		expression = "(z^y)^x";
		maxAns = a;
	}

	cout<<expression<<endl;
	return 0;
}
