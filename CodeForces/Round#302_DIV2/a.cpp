#include <iostream>
#define endl '\n'
using namespace std;

const int maxLen = 100, cntLetters = 26;

bool used[cntLetters + 1];
int n, cntDistinct, distinct[maxLen + 1];
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>s;

	int len = s.size();
	for(int i = 0; i < len; i++)
	{
		if(!used[s[i] - 'a'])
		{
			used[s[i] - 'a'] = true;

			distinct[cntDistinct] = i;
			cntDistinct++;
		}
	}

	if(cntDistinct < n) cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;

		int cntWords = 0, i = 1;
		for(i = 1; i < cntDistinct; i++)
		{
			if(cntWords == n - 1) break;

			cout<<s.substr(distinct[i - 1], distinct[i] - distinct[i - 1])<<endl;
			cntWords++;
		}
		
		i--;
		cout<<s.substr(distinct[i])<<endl;
	}

	return 0;
}
