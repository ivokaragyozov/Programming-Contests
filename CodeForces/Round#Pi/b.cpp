#include <iostream>
#define endl '\n'
using namespace std;

const int maxR = 1e6+1;

bool isIn[maxR];
int n, number, currCnt, maxCnt;
char type;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>type>>number;

		if(type == '-')
		{
			if(isIn[number])
			{
				isIn[number] = false;
				currCnt--;
			}
			else
			{
				maxCnt++;
			}
		}
		else
		{
			isIn[number] = true;
			currCnt++;

			if(currCnt > maxCnt) maxCnt = currCnt;
		}
	}

	cout<<maxCnt<<endl;
	return 0;
}

