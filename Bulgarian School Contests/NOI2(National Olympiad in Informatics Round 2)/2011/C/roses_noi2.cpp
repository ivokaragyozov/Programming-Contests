/**
Ivo Karagyozov
NOI2 2011 C1 roses
*/
#include<iostream>
#include<cstdio>
using namespace std;

int n, m, k, board[1000][1000], sum1[1000][1000], sum2[1000][1000], maxsum=0, totalsum=0;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &board[i][j]);
            totalsum+=board[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(j>=k)
            {
                sum1[i][j]=sum1[i][j-1]+board[i][j]-board[i][j-k];
            }
            else
            {
                if(j!=0)sum1[i][j]=sum1[i][j-1]+board[i][j];
                else sum1[i][j]=board[i][j];
            }
        }
    }
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(i>=k)
            {
                sum2[i][j]=sum2[i-1][j]+sum1[i][j]-sum1[i-k][j];
            }
            else
            {
                if(i!=0)sum2[i][j]=sum2[i-1][j]+sum1[i][j];
                else sum2[i][j]=sum1[i][j];
            }
            if(sum2[i][j]>maxsum)maxsum=sum2[i][j];
        }
    }
    printf("%lld\n", totalsum-maxsum);
    return 0;
}
