#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int cntLetters = 26;

bool hasMadeChange;
string s, t;

bool isPallindrome(string a)
{
	string reversedA = a;
	reverse(reversedA.begin(), reversedA.end());

	return (a == reversedA ? true : false);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>s;
	int len = s.size();
	string letter;
	for(int i = 0; i < cntLetters; i++)
	{
		letter = (char)(i + 'a');

		for(int j = 0; j <= len; j++)
		{
			t = s;
			t.insert(j, letter);

			if(isPallindrome(t))
			{
				cout<<t<<endl;
				return 0;
			}
		}
	}

	cout<<"NA"<<endl;
	return 0;
}
