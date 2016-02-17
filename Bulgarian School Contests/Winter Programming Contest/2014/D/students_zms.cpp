/**
Ivo Karagyozov
Zimni 2014 D3 students
*/
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int s[50005];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	long long maxp=0,student=1;
	for(int i=1;i<n;i++)
	{
		int j=i,p=2;
		bool k=false;
		while(s[i]==s[i-1]+1)
		{
			i++;
			p++;
			if(i>=n)
			{
				i=i%n;
				k=true;
			}
		}
		if(p>maxp)
		{
			maxp=p;
			student=j-(s[j]-1);
			if(student<0)student=n+student;
			student++;
		}
        if(k==true)break;
	}
	cout<<student<<endl;
	return 0;
}

