/**
Ivo Karagyozov
NOI3 2013 D2 pres
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long a[1000]={1,2};
    long long i=1;
    while(a[i]<=n)
    {
        i++;
        a[i]=a[i-1]+a[i-2];
    }
    long long sums[1000];
    i=0;
    while(n>0)
    {
        int j=0;
        while(a[j]<=n)
        {
            j++;
        }
        sums[i]=a[j-1];
        n-=a[j-1];
        i++;
    }
    sort(sums,sums+i);
    for(int k=0;k<i-1;k++)
    {
        cout<<sums[k]<<"+";
    }
    cout<<sums[i-1]<<endl;
    return 0;
}
