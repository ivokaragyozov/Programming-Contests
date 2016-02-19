#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int size_name_guest, cnt_letters[26], size_name_host, size_pile;
string name_guest, name_host, pile;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>name_guest>>name_host>>pile;

	size_name_guest = name_guest.size();
	for(int i = 0; i < size_name_guest; i++)
	{
		cnt_letters[name_guest[i] - 'A']++;
	}
	
	size_name_host = name_host.size();
	for(int i = 0; i < size_name_host; i++)
	{
		cnt_letters[name_host[i] - 'A']++;
	}

	size_pile = pile.size();
	for(int i = 0; i < size_pile; i++)
	{
		cnt_letters[pile[i] - 'A']--;
	}

	for(int i = 0; i < 26; i++)
	{
		if(cnt_letters[i] != 0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}

	cout<<"YES"<<endl;
	return 0;
}
