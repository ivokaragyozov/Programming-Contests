#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int count=0,countx,county;
	long double x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
		if(x1<x2)
		countx=(x2-x1);
		else
	    countx=(x1-x2);

		if(y1<y2)
		county=(y2-y1);
		else
		county=(y1-y2);


if(countx<county)
{
	count+=countx;
	if(y1>y2)
	{y1-=countx;
	count+=(y1-y2);}
	else
	{y2-=countx;
	count+=(y2-y1);}
}

if(county<countx)
{
	count+=county;
	if(x1>x2)
	{x1-=county;
	count+=(x1-x2);}
	else
	{x2-=county;
	count+=(x2-x1);}
}

if(count==0)
count=countx;

cout<<count;

return 0;
}
