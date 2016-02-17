/**
Ivo Karagyozov
NOI2 2010 C3 rod
*/
#include<iostream>
#include<cstdio>
using namespace std;

int n, a[1000], sums[1000][1000], dyn[1000][1000];

void gensums()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int sum=0;
            for(int k=i; k<=j; k++)
            {
                sum+=a[k];
            }
            sums[i][j]=sum;
        }
    }
}
int minsum(int i, int j)
{
    if(i==j)return 0;
    if(dyn[i][j]!=0)return dyn[i][j];
    int m=1<<30;
    for(int k=i; k<j; k++)
    {
        int r1=minsum(i, k);
        int r2=minsum(k+1, j);
        int sum=r1+r2+sums[i][k]+sums[k+1][j];
        if(sum<m)m=sum;
    }
    dyn[i][j]=m;
    return m;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    gensums();
    printf("%d\n", minsum(0, n-1));
    return 0;
}
