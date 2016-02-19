#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool used_letters[26];
int size_s, ans;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, s);
	size_s = s.size();
	for(int i = 0; i < size_s; i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			if(!used_letters[s[i] - 'a'])
			{
				used_letters[s[i] - 'a'] = true;
				ans++;
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}
