/**
Ivo Karagyozov
NOI1 2012 C1 balls
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long nums[105];
bool binaryS(long long target, int n)
{
    int ri=0, le=n-1;
    if(le<0)return false;
    while(ri<=le)
    {
        int mid=(ri+le)/2;
        if(nums[mid]<target)
        {
            ri=mid+1;
        }
        else if(nums[mid]>target)
        {
            le=mid-1;
        }
        else return true;
    }
    return false;
}
int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    int br=0;
    for(int i=0; i<k; i++)
    {
        scanf("%lld", &nums[i]);
        if(binaryS(nums[i], i)==false)
        {
            br++;
        }
        sort(nums, nums+i+1);
    }
    long long ans=n-br;
    printf("%lld\n", ans);
    return 0;
}
