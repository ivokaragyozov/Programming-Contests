#include <iostream>
#define endl '\n'
using namespace std;

int cnt2, cnt3, cnt5, cnt7, n;
string number;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>number;

	for(int i = 0; i < n; i++)
	{
		if(number[i] == '0' || number[i] == '1') continue;
		else if(number[i] == '2') cnt2++;
		else if(number[i] == '3') cnt3++;
		else if(number[i] == '4') 
		{
			cnt2 += 2;
			cnt3++;
		}
		else if(number[i] == '5') cnt5++;
		else if(number[i] == '6')
		{
			cnt3++;
			cnt5++;
		}
		else if(number[i] == '7')
		{
			cnt7++;
		}
		else if(number[i] == '8')
		{
			cnt2 += 3;
			cnt7++;
		}
		else
		{
			cnt2++;
			cnt3 += 2;
			cnt7++;
		}
	}

	for(int i = 0; i < cnt7; i++) cout<<7;
	for(int i = 0; i < cnt5; i++) cout<<5;
	for(int i = 0; i < cnt3; i++) cout<<3;
	for(int i = 0; i < cnt2; i++) cout<<2;

	cout<<endl;
	return 0;
}
