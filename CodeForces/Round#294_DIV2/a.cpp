#include <iostream>
#define endl '\n'
using namespace std;

char a;
int scoreWhite, scoreBlack;

int getScore(char c)
{
	if(c == 'Q') return 9;
	if(c == 'R') return 5;
	if(c == 'B') return 3;
	if(c == 'N') return 3;
	if(c == 'P') return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i = 0; i < 64; i++)
	{
		cin>>a;

		if(a == '.') continue;

		if(a >= 'a' && a <= 'z')
		{
			a = a - 'a' + 'A';

			scoreBlack += getScore(a);
		}
		else scoreWhite += getScore(a);
	}

	if(scoreWhite == scoreBlack) cout<<"Draw"<<endl;
	else cout<<(scoreWhite > scoreBlack ? "White" : "Black")<<endl;

	return 0;
}
