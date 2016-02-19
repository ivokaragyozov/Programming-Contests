#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a1, a2, a3, b1, b2, b3, cnt_shelves, sum_cups, sum_medals, cnt_shelves_cups, cnt_shelves_medals;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>a1>>a2>>a3>>b1>>b2>>b3>>cnt_shelves;

	sum_cups = a1 + a2 + a3;
	sum_medals = b1 + b2 + b3;

	if(sum_cups % 5 == 0) cnt_shelves_cups = sum_cups / 5;
	else cnt_shelves_cups = sum_cups / 5 + 1;

	if(sum_medals % 10 == 0) cnt_shelves_medals = sum_medals / 10;
	else cnt_shelves_medals = sum_medals / 10 + 1;

	if(cnt_shelves_cups + cnt_shelves_medals > cnt_shelves) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}
