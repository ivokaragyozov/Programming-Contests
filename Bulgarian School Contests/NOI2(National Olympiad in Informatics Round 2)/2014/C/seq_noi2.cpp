/**
Ivo Karagyozov
NOI2 2014 C1 seq
*/
#include<iostream>
using namespace std;
long long n, a[100000], dyn[100000][2];
int main()
{
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	dyn[0][0]=2*a[0];
	dyn[0][1]=3*a[0];
	for(int i=1; i<n; i++)
	{
		dyn[i][0]=max(dyn[i-1][0], dyn[i-1][1])+2*a[i];
		dyn[i][1]=dyn[i-1][0]+3*a[i];
	}
	cout<<max(dyn[n-1][0], dyn[n-1][1])<<endl;
	return 0;
}
