#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int ans, lastInd, currInd, findT, p;
string s, t, a;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>s>>t;
	
	a = s;
	while(1)
	{
		if(currInd >= s.size() - 1) break;

		findT = a.find(t);
		if(findT == string::npos) break;
		else
		{
			currInd = findT + p;
			if(currInd < s.size() - 1) a = s.substr(currInd + 1);
			p = t.size() + currInd;
			if(currInd - lastInd >= t.size() || ans == 0) ans++;
			lastInd = currInd;
		}
	}

	cout<<ans<<endl;
	return 0;
}
