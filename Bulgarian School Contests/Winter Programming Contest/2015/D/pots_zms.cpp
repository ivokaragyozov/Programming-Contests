/**
Ivo Karagyozov
Zimni 2015 D3 pots
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, a[100005], b[100005], br=0;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d", &b[i]);
    }
    sort(a, a+n);
    sort(b, b+m);
    int ind1=0, ind2=0;
    for(int i=0; i<max(n, m); i++)
    {
        if(b[ind2]>=a[ind1])
        {
            br++;
            ind1++;
            ind2++;
        }
        else
        {
            ind2++;
        }
    }
    printf("%d\n", br);
    return 0;
}
