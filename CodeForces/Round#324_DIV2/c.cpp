#include <iostream>
#define endl '\n'
using namespace std;

int n, k, p, cntEqual, cntDiffS, cntDiffT;
string s, t, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>k>>s>>t;

	if(k == 0 && s != t)
	{
		cout<<-1<<endl;
		return 0;
	}

	cntDiffS = cntDiffT = k;
	ans.resize(n);
	p = n - k;

	for(int i = 0; i < n; i++)
	{
		if(s[i] == t[i]) cntEqual++;
	}

	if(p <= cntEqual)
	{
		cntEqual = 0;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == t[i] && cntEqual < p)
			{
				cntEqual++;
				ans[i] = s[i];
			}
			else
			{
				if(s[i] != 'a' && t[i] != 'a') ans[i] = 'a';
				else if(s[i] != 'b' && t[i] != 'b') ans[i] = 'b';
				else ans[i] = 'c';
			}
		}
	}
	else
	{
		if(n - cntEqual < 2 * (p - cntEqual))
		{
			cout<<-1<<endl;
			return 0;
		}

		cntDiffS = p - cntEqual;
		cntDiffT = p - cntEqual;

		for(int i = 0; i < n; i++)
		{
			if(s[i] == t[i]) ans[i] = s[i];
			else
			{
				if(cntDiffS != 0)
				{
					ans[i] = t[i];
					cntDiffS--;
				}
				else if(cntDiffT != 0)
				{
					ans[i] = s[i];
					cntDiffT--;
				}
				else
				{
					if(s[i] != 'a' && t[i] != 'a') ans[i] = 'a';
					else if(s[i] != 'b' && t[i] != 'b') ans[i] = 'b';
					else ans[i] = 'c';
				}
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}
