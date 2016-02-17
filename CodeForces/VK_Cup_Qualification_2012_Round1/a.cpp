#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 50;

int n, k, a[maxN + 5], answer;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>k;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	sort(a, a + n, cmp);

	for(int i = 0; i < n; i++)
	{
		if(i < k && a[i] > 0) answer++;
		else
		{
			if(a[i] <= 0) break;
			else
			{
				if(a[i] == a[i - 1]) answer++;
				else break;
			}
		}
	}

	cout<<answer<<endl;
	return 0;
}
