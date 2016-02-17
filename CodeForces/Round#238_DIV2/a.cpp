#include <iostream>
#define endl '\n'
using namespace std;

const int maxN = 100;

int n, a[maxN + 1], cntPerRow[maxN + 1], maxHeight = 0, currCol;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];

		if(a[i] > maxHeight) maxHeight = a[i];

		for(int j = a[i]; j >= 0; j--)
		{
			cntPerRow[j]++;
		}
	}

	for(int i = 0; i < n; i++)
	{
		currCol = 0;

		for(int j = maxHeight; j >= 1; j--)
		{
			currCol += (i >= n-cntPerRow[j] ? 1 : 0);
			//cout<<"i = "<<i<<"   j = "<<j<<"    n-cntPerRow[j] = "<<n-cntPerRow[j]<<"   currCol = "<<currCol<<endl;
		}

		cout<<currCol<<" ";
	}
	
	cout<<endl;
	return 0;
}
