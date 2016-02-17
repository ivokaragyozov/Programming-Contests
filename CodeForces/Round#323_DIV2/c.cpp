#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define endl '\n'
using namespace std;

const int maxN = 500;

int n, a[maxN * maxN + 5], ind, cntTaken, currCnt, cnt1;
map<int, int> cnt;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n * n; i++)
	{
		cin>>a[i];
	}

	ind = n * n - 1;

	sort(a, a + n * n);
	for(int i = ind; i >= 0; i--)
	{
		if(answer.size() == n) break;
		if(i == 0 || a[i - 1] != a[i])
		{
			answer.push_back(a[i]);
			cntTaken++;

			if(cntTaken == n) break;
		}
		else
		{
			currCnt = 1;
			while(i != 0 && a[i - 1] == a[i])
			{
				currCnt++;
				i--;
			}
			
			if(cnt.find(a[i]) != cnt.end()) cnt1 = cnt[a[i]];
			else cnt1 = 0;
			while(cnt1 <= currCnt && currCnt != 0)
			{
				answer.push_back(a[i]);
				if(answer.size() == n) break;

				for(int j = answer.size() - 2; j >= 0; j--)
				{
					if(answer[j] % a[i]) cnt1 += 2; 
				}
				cnt1++;
				currCnt--;
			}

			cnt[a[i]] = cnt1;
		}
	}


	for(int i = 0; i < n; i++)
	{
		cout<<answer[i]<<" ";
	}

	return 0;
}
