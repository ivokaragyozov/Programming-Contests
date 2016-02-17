#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int cntLetters = 26, maxLen = 1e5;

int x[cntLetters + 1], dp[maxLen + 1], answer;
string s;
vector<int> v[cntLetters];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i = 0; i < cntLetters; i++)
	{
		cin>>x[i];
	}
	cin>>s;

	int len = s.size(), len1;
	for(int i = 0; i < len; i++)
	{
		if(i == 0) dp[i] = x[s[i] - 'a'];
		else dp[i] = dp[i - 1] + x[s[i] - 'a'];

		len1 = v[s[i] - 'a'].size();
		for(int j = 0; j < len1; j++)
		{
			if(dp[i] - dp[v[s[i] - 'a'][j]] == x[s[i] - 'a']) answer++;
		}

		v[s[i] - 'a'].push_back(i);
	}

	cout<<answer<<endl;
	return 0;
}
