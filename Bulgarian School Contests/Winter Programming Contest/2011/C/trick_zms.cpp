/**
Ivo Karagyozov
Zimni 2011 C3 trick
*/
#include<iostream>
#include<cstdio>
using namespace std;

char zn[100000];
int nums[100000], ind=0;

int main()
{
    while(1)
    {
        cin>>zn[ind]>>nums[ind];
        if(zn[ind]=='=')break;
        else ind++;
    }
    int ans=nums[ind];
    for(int i=ind-1; i>=0; i--)
    {
        if(zn[i]=='+')ans=ans-nums[i];
        else if(zn[i]=='-')ans=ans+nums[i];
        else if(zn[i]=='*')ans=ans/nums[i];
        else ans=ans*nums[i];
    }
    printf("%d\n", ans);
    return 0;
}
