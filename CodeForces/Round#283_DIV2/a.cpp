#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n, a[105];
    scanf("%d", &n);
    int minR=10000000, maxR=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        if(i!=0)
        {
            if(a[i]-a[i-1]>maxR)maxR=a[i]-a[i-1];
        }
    }
    int minR1=maxR;
    for(int i=2; i<n; i++)
    {
        int r=a[i]-a[i-2];
        if(r<minR)minR=r;
    }
    printf("%d\n", max(minR, minR1));
    return 0;
}
