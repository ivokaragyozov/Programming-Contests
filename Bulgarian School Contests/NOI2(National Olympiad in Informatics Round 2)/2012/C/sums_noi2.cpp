/**
Ivo Karagyozov
Zimni 2012 C2 sums
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int sums[100005];
int main()
{
    int n, be, en;
    scanf("%d %d %d", &n, &be, &en);
    int a[105], sum=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    int pMax=a[1], pMin=a[1];
    for(int i=1; i<=n; i++)
    {
        for(int j=pMax; j>=pMin; j--)
        {
            if(sums[j]!=0 && sums[j+a[i]]==0)
            {
                sums[j+a[i]]=i;
                if(j+a[i]>pMax)pMax=j+a[i];
            }
        }
        if(sums[a[i]]==0)
        {
            sums[a[i]]=i;
            if(a[i]<pMin)pMin=a[i];
            else pMax=a[i];
        }
    }
    int br=0;
    for(int i=be; i<=en; i++)
    {
        if(sums[i]!=0)br++;
    }
    printf("%d\n", br);
    return 0;
}
