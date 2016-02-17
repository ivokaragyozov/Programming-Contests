/**
Ivo Karagyozov
NOI2 2011 C3 robot
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n, m, r, k, board[105][105], ir=0, jr=0, p=1;
long long sum=0;
bool used[105][105];

int main()
{
    scanf("%d%d%d%d", &n, &m, &r, &k);
    p=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            board[i][j]=p;
            p++;
            if(board[i][j]==r)
            {
                ir=i;
                jr=j;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int raz=abs(ir-i)+abs(jr-j);
            if(raz<=k && raz%2==k%2)
            {
                sum+=board[i][j];
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
