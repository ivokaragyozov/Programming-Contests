#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, ans;
string s;

bool samePlace(string t)
{
	int x = 0, y = 0;
	for(int i = 0; i < t.size(); i++)
	{
		if(t[i] == 'U') y++;
		else if(t[i] == 'D') y--;
		else if(t[i] == 'R') x++;
		else x--;
	}

	if(x == 0 && y == 0) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>s;
	for(int i = 0; i < s.size(); i++)
	{
		for(int j = i + 1; j < s.size(); j++)
		{
			if(samePlace(s.substr(i, j - i + 1))) ans++;
		}
	}

	cout<<ans<<endl;
	return 0;
}
