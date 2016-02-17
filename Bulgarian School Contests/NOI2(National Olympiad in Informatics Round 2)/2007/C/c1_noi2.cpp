/**
Ivo Karagyozov
2007 NOI2 C1 c1
*/
#include<iostream>
#include<cstdio>
using namespace std;

int n1, m1, n2, m2, a_row[105][105], a_col[105][105], b_row[105][105], b_col[105][105];

int nod(int a, int b)
{
    while(b>0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    scanf("%d%d", &n1, &m1);
    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=m1; j++)
        {
            int num;
            scanf("%d", &num);
            a_col[i][j]=a_col[i-1][j]+num;
            a_row[i][j]=a_row[i][j-1]+num;
        }
    }
    scanf("%d%d", &n2, &m2);
    for(int i=1; i<=n2; i++)
    {
        for(int j=1; j<=m2; j++)
        {
            int num;
            scanf("%d", &num);
            b_col[i][j]=b_col[i-1][j]+num;
            b_row[i][j]=b_row[i][j-1]+num;
        }
    }
    int nodd1=a_col[n1][1], nodd2=b_col[n2][1];
    for(int i=2; i<=m1; i++)nodd1=nod(nodd1, a_col[n1][i]);
    for(int i=1; i<=n1; i++)nodd1=nod(nodd1, a_row[i][m1]);
    for(int i=2; i<=m2; i++)nodd2=nod(nodd2, b_col[n2][i]);
    for(int i=1; i<=n2; i++)nodd2=nod(nodd2, b_row[i][m2]);
    printf("%d %d\n", nodd1, nodd2);
    if(max(nodd1, nodd2)%min(nodd1, nodd2)==0)printf("Y");
    else printf("N");
    return 0;
}
