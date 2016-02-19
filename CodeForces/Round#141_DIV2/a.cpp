#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int s1, s2, s3, s4, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>s1>>s2>>s3>>s4;
	
	ans = 1;
	if(s2 != s1) ans++;
	if(s3 != s2 && s3 != s1) ans++;
	if(s4 != s3 && s4 != s2 && s4 != s1) ans++;

	cout<<4 - ans<<endl;
	return 0;
}
