#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 100;

int n, m, cntHappyBoys, cntHappyGirls, happyBoy, happyGirl, girlInd, boyInd;
bool boys[maxN + 1], girls[maxN + 1], answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;

	cin>>cntHappyBoys;
	for(int i = 0; i < cntHappyBoys; i++)
	{
		cin>>happyBoy;

		boys[happyBoy] = true;
	}

	cin>>cntHappyGirls;
	for(int i = 0; i < cntHappyGirls; i++)
	{
		cin>>happyGirl;

		girls[happyGirl] = true;
	}

	for(int i = 0; i < n * n * m * m; i++)
	{
		if(cntHappyBoys == n && cntHappyGirls == m) 
		{
			answer = true;
			break;
		}

		boyInd = i % n;
		girlInd = i % m;

		if(boys[boyInd] && !girls[girlInd])
		{
			cntHappyGirls++;
			girls[girlInd] = true;
		}
		else if(!boys[boyInd] && girls[girlInd])
		{
			cntHappyBoys++;
			boys[boyInd] = true;
		}
	}

	cout<<(answer ? "Yes" : "No")<<endl;
	return 0;
}
