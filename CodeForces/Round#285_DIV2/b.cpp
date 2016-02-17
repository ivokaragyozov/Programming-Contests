#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

int n;
string oldHendle, newHendle, firstHendle;
map<string, string> users;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>oldHendle>>newHendle;

		if(users.find(oldHendle) != users.end())
		{
			firstHendle = users[oldHendle];

			users.erase(oldHendle);
			users[newHendle] = firstHendle;
		}
		else users[newHendle] = oldHendle;
	}
	
	cout<<users.size()<<endl;
	map<string, string>::iterator it = users.begin();
	for(; it != users.end(); it++)
	{
		cout<<it->second<<" "<<it->first<<endl;
	}

	return 0;
}
