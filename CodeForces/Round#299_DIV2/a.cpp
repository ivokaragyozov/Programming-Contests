#include <iostream>
#define endl '\n'
using namespace std;

int s;
string units[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}, tenths[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}, teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

string nameOfNumber(int a)
{
	if(s < 10)
	{
		return units[s];
	}
	else if(s < 20)
	{
		return teens[s % 10];
	}
	else
	{
		if(s % 10 == 0) return tenths[s / 10];
		else return tenths[s / 10] + "-" + units[s % 10];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>s;
	cout<<nameOfNumber(s)<<endl;
	return 0;
}
