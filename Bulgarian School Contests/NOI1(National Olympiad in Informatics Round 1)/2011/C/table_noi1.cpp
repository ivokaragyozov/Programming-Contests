/**
Ivo Karagyozov
NOI1 2011 C2 table
*/
#include<iostream>
#include<cstdio>
using namespace std;
int table[105][105], n, m, k, p, q;
void fromNumToInd(int num)
{
    p=num/m;
    q=num%m;
    if(q==0)
    {
        p--;
        q=m;
    }
    q--;
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &table[i][j]);
        }
    }
    int ind=k;
    long long sum=0;
    while(ind<=n*m)
    {
        fromNumToInd(ind);
        sum+=table[p][q];
        ind+=k;
    }
    printf("%lld\n", sum);
    return 0;
}
