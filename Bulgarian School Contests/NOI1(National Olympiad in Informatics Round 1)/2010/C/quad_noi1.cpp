/**
Ivo Karagyozov
NOI1 2010 C2 quad
*/
#include<iostream>
#include<cstdio>
using namespace std;
int board[105][105], indNum=0, iK=0, jK=0;
int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &board[i][j]);
            indNum++;
            if(indNum==k)
            {
                iK=i;
                jK=j;
            }
        }
    }
    int sum1=0, sum2=0, sum3=0, sum4=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i<iK && j>jK)sum1+=board[i][j];
            else if(i<iK && j<jK)sum2+=board[i][j];
            else if(i>iK && j<jK)sum3+=board[i][j];
            else if(i>iK && j>jK)sum4+=board[i][j];

        }
    }
    printf("%d %d %d %d\n", sum1, sum2, sum3, sum4);
    return 0;
}
