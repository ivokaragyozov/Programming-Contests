#include<iostream>
#include<cstdio>
#define endl '\n'
using namespace std;

const int maxLen = 200000;

int cntDiff;
char diffs[maxLen + 1][2];
string s, t;

int main()
{
	ios_base::sync_with_stido(false);
	cin.tie(NULL);

	cin>>s>>t;

	int len = s.size();
	for(int i = 0; i < len; i++)
	{
		if(s[i] != t[i]) 
		{
			diffs[cntDiff][0] = s[i];
			diffs[cntDiff][1] = t[i];

			cntDiff++;
		}
	}


}
