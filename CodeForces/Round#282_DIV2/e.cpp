#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
double a[10005];
int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++)
    {
        scanf("%lf", &a[i]);
    }
    for(int i=0; i<q; i++)
    {
        int r, l;
        double p;
        scanf("%d %d %lf", &r, &l, &p);
        for(int j=r; j<=l; j++)
        {
            a[j]+=p;
        }
    }
    cout<<fixed<<setprecision(9);
    sort(a+1, a+n+1);
    printf("%lf\n", a[n]);
    return 0;
}
