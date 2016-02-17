#include <iostream>
#define endl '\n'
using namespace std;

bool legs;
int l, cntSticks[10], head = -1, body = -1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i = 0; i < 6; i++)
	{
		cin>>l;

		cntSticks[l]++;
	}

	for(int i = 1; i < 10; i++)
	{
		if(cntSticks[i] >= 4)
		{
			if(cntSticks[i] >= 5) head = i;
			if(cntSticks[i] == 6) body = i;
		}
		else
		{
			while(cntSticks[i] > 0)
			{
				if(body == -1) body = i;
				else if(head == -1) head = i;
				else
				{
					cout<<"Alien"<<endl;
					return 0;
				}
				cntSticks[i]--;
			}
		}
	}
	
	cout<<(head == body ? "Elephant" : "Bear")<<endl;
	return 0;
}
