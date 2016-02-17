#include <iostream>
#define endl '\n'
using namespace std;

const int cntLET = 26;

int n, m, cntS[cntLET + 1], cntT[cntLET + 1], answer;
string s, t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>s>>t;

	n = s.size();
	m = t.size();
	
	for(int i = 0; i < s.size(); i++)
	{
		cntS[s[i] - 'a']++;
	}
	for(int i = 0; i < t.size(); i++)
	{
		cntT[t[i] - 'a']++;
	}

	for(int i = 0; i < 26; i++)
	{
		if(cntS[i] == 0 && cntT[i] != 0)
		{
			cout<<-1<<endl;
			return 0;
		}
		else answer += min(cntS[i], cntT[i]);
	}

	cout<<answer<<endl;
	return 0;
}
