#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 1000;

bool dir, vis[maxN + 5];
int n, a[maxN + 5], cntTaken, currPos, answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	while(1)
	{
		if(cntTaken >= a[currPos] && !vis[currPos])
		{
			vis[currPos] = true;
			cntTaken++;
		}
		if(cntTaken == n) break;

		if(!dir)
		{
			currPos++;
			if(currPos == n) 
			{
				currPos--;
				dir = !dir;
				answer++;
			}
		}
		else
		{
			currPos--;
			if(currPos == -1)
			{
				currPos++;
				dir = !dir;
				answer++;
			}
		}
	}
	
	cout<<answer<<endl;
	return 0;
}
