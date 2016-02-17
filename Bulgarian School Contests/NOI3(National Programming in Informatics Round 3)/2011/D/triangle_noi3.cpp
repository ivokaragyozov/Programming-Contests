/**
Ivo Karagyozov
NOI3 2011 D5 triangle
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=n-1;i>=1;i--)
    {
        if(n%i==0)
        {
            n=n/i+i-1;
            break;
        }
    }
    long long sum=n;
    n--;
    for(int i=n,j=2;i>0;i--,j++)
    {
        sum=sum+i*j;
    }
    cout<<sum<<endl;
    return 0;
}
