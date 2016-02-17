#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

const int maxLen = 1e5;

string s, t;
int diffs[maxLen + 1], cntDiff, firstDiff;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>s>>t;

	int len = s.size();
	for(int i = 0; i < len; i++)
	{
		if(s[i] != t[i])
		{
			diffs[cntDiff] = i;
			cntDiff++;
		}
	}

	if(cntDiff % 2 != 0)
	{
		cout<<"impossible"<<endl;
		return 0;
	}
	else if(cntDiff == 0)
	{
		cout<<s<<endl;
		return 0;
	}

	for(int i = 0; i < cntDiff / 2; i++)
	{
		if(s[diffs[i]] == '0') s[diffs[i]] = '1';
		else s[diffs[i]] = '0';
	}

	cout<<s<<endl;
	return 0;
}
