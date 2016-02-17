/**
Ivo Karagyozov
NOI1 2009 C1 maxk
*/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[1005];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    int sum=0, maxSum=0;
    for(int i=0; i<n; i++)
    {
        if(i<k)
        {
            sum+=a[i];
        }
        else
        {
            if(sum>maxSum)maxSum=sum;
            sum-=a[i-k];
            sum+=a[i];
        }
    }
    if(sum>maxSum)maxSum=sum;
    printf("%d\n", maxSum);
    return 0;
}
