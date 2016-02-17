/**
Ivo Karagyozov
NOI2 2008 C2 angles
*/
#include<iostream>
#include<cstdio>
using namespace std;

int n, k, sums_row[1005][1005], sums_col[1005][1005], maxsum=0, ind1, ind2;

int main()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int a;
            scanf("%d", &a);
            sums_row[i][j]=sums_row[i-1][j]+a;
            sums_col[i][j]=sums_col[i][j-1]+a;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int maxleft=min(j+1+k, n), maxdown=min(i+k, n), p;
            int sum=(sums_col[i][maxleft]-sums_col[i][j])+(sums_row[maxdown][j]-sums_row[i-1][j]);
            if(sum>maxsum)
            {
                maxsum=sum;
                ind1=i;
                ind2=j;
            }
        }
    }
    printf("%d %d\n", ind1, ind2);
    return 0;
}
