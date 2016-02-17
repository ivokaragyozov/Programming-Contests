#include<iostream>
#include<cstdio>
using namespace std;

long long a, b, answer;

int main()
{
	cin>>a>>b;


	while(a > 0 && b > 0)
	{
		if(a >= b)
		{
			answer += a / b;
			a %= b;
		}
		else
		{
			answer += b / a;
			b %= a;
		}
	}

	cout<<answer<<endl;
    return 0;
}
