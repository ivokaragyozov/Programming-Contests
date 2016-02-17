#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, cntB, cntG, cntR;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'B') cntB++;
		else if(s[i] == 'G') cntG++;
		else cntR++;
	}

	if(cntB > 0 && cntG > 0 && cntR > 0) cout<<"BGR"<<endl;
	else if(cntB > 0 && cntG == 0 && cntR == 0) cout<<"B"<<endl;
	else if(cntB == 0 && cntG > 0 && cntR == 0) cout<<"G"<<endl;
	else if(cntB == 0 && cntG == 0 && cntR > 0) cout<<"R"<<endl;
	else if(cntB == 1 && cntG == 1 && cntR == 0) cout<<"R"<<endl;
	else if(cntB == 1 && cntG == 0 && cntR == 1) cout<<"G"<<endl;
	else if(cntB == 0 && cntG == 1 && cntR == 1) cout<<"B"<<endl;
	else if((cntB > 1 && cntG > 1) || (cntB > 1 && cntR > 1) || (cntG > 1 && cntR > 1)) cout<<"BGR"<<endl;
	else if(cntB > 1 && cntG == 1 && cntR == 0) cout<<"GR"<<endl;
	else if(cntB > 1 && cntG == 0 && cntR == 1) cout<<"GR"<<endl;
	else if(cntB == 1 && cntG > 1 && cntR == 0) cout<<"BR"<<endl;
	else if(cntB == 1 && cntG == 0 && cntR > 1) cout<<"BG"<<endl;
	else if(cntB == 0 && cntG > 1 && cntR == 1) cout<<"BR"<<endl;
	else if(cntB == 0 && cntG == 1 && cntR > 1) cout<<"BG"<<endl;

	return 0;
}
