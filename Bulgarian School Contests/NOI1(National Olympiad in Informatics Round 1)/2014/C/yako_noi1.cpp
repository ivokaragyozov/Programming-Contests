/**
Ivo Karagyozov
NOI1 2014 C3 yako
*/
#include<iostream>
#include<algorithm>
using namespace std;
bool isprime(int n)
{
    if(n<2)return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)return false;
    }
    return true;
}
int main()
{
    int a,b;
    cin>>a>>b;
    int num[1000],j=0;
    for(int i=a;i<=b;i++)
    {
        int p=i,sum=0;
        while(p>0)
        {
            sum=sum+p%10;
            p=p/10;
        }
        if(sum>=10 && sum<99 && isprime(i)==true && isprime(sum)==true)
        {
            num[j]=i;
            j++;
        }
    }
    if(j==0)
    {
        cout<<0<<endl;
        return 0;
    }
    sort(num,num+j);
    for(int i=0;i<j-1;i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<num[j-1]<<endl;
    return 0;
}
