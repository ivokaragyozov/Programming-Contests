/**
Ivo Karagyozov
Zimni 2014 D1 line
*/
#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int i=1,j=1;
	long long br=1;
	int i1=0,j1=0;
	while(1)
	{
		int i2=i;
		int j2=j;
		if(i==0 || j==0 || i==n-1 || j==m-1)
		{
			br++;
			if(i==0)
			{
				i=1;
				if(j1>j)j--;
				else j++;
			}
			else if(j==0)
			{
				j=1;
				if(i1>i)i--;
				else i++;
			}
			else if(i==n-1)
			{
				i=n-2;
				if(j1>j)j--;
				else j++;
			}
			else
			{
				j=m-2;
				if(i1>i)i--;
				else i++;
			}
		}
		else
		{
			if(i>i1)
			{
				i++;
			}
			else if(i<=i1)
			{
				i--;
			}
			if(j>j1)
			{
				j++;
			}
			else if(j<j1)
			{
				j--;
			}
		}
		i1=i2;
		j1=j2;
		if((i==0 && j==0) || (i==0 && j==m-1) || (i==n-1 && j==0) || (i==n-1 && j==m-1))break;
	}
	cout<<br<<endl;
	return 0;
}

