#include <iostream>
#define endl '\n'
using namespace std;

string s, t;

bool isVolew(char a)
{
	if(a == 'a' || a == 'o' || a == 'y' || a == 'e' || a == 'u' || a == 'i') return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>s;

	int len = s.size();
	for(int i = 0; i < len; i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';

		if(isVolew(s[i])) continue;
		else t = t + '.' + s[i];
	}


	cout<<t<<endl;
	return 0;
}
