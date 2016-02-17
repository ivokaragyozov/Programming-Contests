#include <iostream>
#define endl '\n'
using namespace std;

int n;
string word;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>word;

		if(word.size() > 10) cout<<word[0]<<word.size() - 2<<word[word.size() - 1]<<endl;
		else cout<<word<<endl;
	}

	return 0;
}
