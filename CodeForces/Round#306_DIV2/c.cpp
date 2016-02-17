#include <iostream>
#define endl '\n'
using namespace std;

int a;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>s;
	
	int len = s.size();

	for(int i = 0; i < len; i++)
	{
		if(s[i] == '8' || s[i] == '0')
		{
			cout<<"YES"<<endl<<s[i]<<endl;
			return 0;
		}
	}

	for(int i = 0; i < len; i++)
	{
		for(int j = i + 1; j < len; j++)
		{
			a = (s[i] - '0') * 10 + (s[j] - '0');

			if(a % 8 == 0)
			{
				cout<<"YES"<<endl<<a<<endl;
				return 0;
			}
		}
	}

	for(int i = 0; i < len; i++)
	{
		for(int j = i + 1; j < len; j++)
		{
			for(int p = j + 1; p < len; p++)
			{
				a = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[p] - '0');

				if(a % 8 == 0)
				{
					cout<<"YES"<<endl<<a<<endl;
					return 0;
				}
			}
		}
	}

	cout<<"No"<<endl;
	return 0;
}
