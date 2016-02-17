/**
Ivo Karagyozov
Zimni 2015 D2 luggage
*/
#include<iostream>
#include<cstdio>
using namespace std;

int s, n, a[105], dyn[10005];

int main()
{
    scanf("%d%d", &s, &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=s; i++)
    {
        dyn[i]=10005;
        for(int j=0; j<n; j++)
        {
            if(i==a[j])dyn[i]=1;
            else if(i<a[j])continue;
            else
            {
                dyn[i]=min(dyn[i-a[j]]+1, dyn[i]);
            }
        }
    }
    printf("%d\n", dyn[s]);
    return 0;
}
