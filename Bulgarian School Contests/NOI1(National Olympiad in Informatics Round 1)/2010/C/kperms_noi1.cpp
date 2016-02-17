/**
Ivo Karagyozov
NOI1 2010 C1 kperms
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[10];
    for(int i=1; i<=n; i++)
    {
        a[i-1]=i;
    }
    int br=0;
    do
    {
        bool p=true;
        for(int i=1; i<n; i++)
        {
            if(max(a[i], a[i-1])-min(a[i], a[i-1])>k)
            {
                p=false;
                break;
            }
        }
        if(p==true)br++;
    }
    while(next_permutation(a, a+n));
    printf("%d\n", br);
    return 0;
}
