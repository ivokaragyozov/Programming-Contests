/**
Ivo Karagyozov
Zimni 2014 D2 monitors
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct info
{
	long long w;
	long long h;
};
int f1(info a,info b)
{
	return a.h>b.h;
}
info t[100005];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t[i].w>>t[i].h;
	}
	t[n].w=0;
	sort(t,t+n,f1);
	t[n].h=t[n-1].h;
	long long maxsum=0;
	for(int i=1;i<=n;i++)
	{
		long long sum=t[i-1].w;
		while(t[i].h==t[i-1].h)
		{
			sum=sum+t[i].w;
			i++;
			if(i==n)break;
		}
		if(sum>maxsum)maxsum=sum;
	}
	cout<<maxsum<<endl;
	return 0;
}

