/**
Ivo Karagyozov
NOI2 2009 C1 twop
*/
#include<iostream>
#include<cstdio>
using namespace std;

int n, maxbr=0;
bool er[5000005];

int main()
{
    scanf("%d", &n);
    er[0]=1;
    er[1]=1;
    for(int i=2; i*i<=5000000; i++)
    {
        if(er[i]==0)
        {
            for(int j=i*i; j<=5000000; j+=i)
            {
                er[j]=1;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        int a, br=0;
        scanf("%d", &a);
        for(int j=2; j<=a/2; j++)
        {
            if(er[j]==0 && er[a-j]==0)br++;
        }
        if(br>maxbr)maxbr=br;
    }
    printf("%d\n", maxbr);
    return 0;
}
