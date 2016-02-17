#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long k, curr_cnt, curr_number, curr, reversed_number;

int size_of_number(long long number)
{
	int cnt_digits = 0;

	while(number > 0)
	{
		number /= 10;
		cnt_digits++;
	}

	return cnt_digits;
}
long long reverse_number(long long number)
{
	long long reversed = 0;
	
	while(number > 0)
	{
		reversed = reversed * 10 + number % 10;
		number /= 10;
	}

	return reversed;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>k;
	curr = 1;
	while(1)
	{
		curr_number = curr * curr;
		curr++;
		curr_cnt += size_of_number(curr_number);
		if(curr_cnt >= k)
		{
			curr_cnt -= size_of_number(curr_number);
			break;
		}
	}

	reversed_number = reverse_number(curr_number);
	while(1)
	{
		curr_cnt++;
		if(curr_cnt == k)
		{
			cout<<reversed_number % 10<<endl;
			return 0;
		}
		reversed_number /= 10;
	}

	return 0;
}
