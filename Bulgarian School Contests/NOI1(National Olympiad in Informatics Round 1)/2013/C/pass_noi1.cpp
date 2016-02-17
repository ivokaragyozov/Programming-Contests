/**
Ivo Karagyozov
NOI1 2013 C2 pass
*/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int a[105];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    int m;
    scanf("%d", &m);
    int b[105];
    for(int i=0; i<m; i++)
    {
        scanf("%d", &b[i]);
    }
    int ind2=0, pass[105], ind=0;
    for(int i=0; i<m; i++)
    {
        if(a[ind2]!=b[i])
        {
            int sum=0;
            while(sum!=b[i])
            {
                sum+=a[ind2];
                pass[ind]=a[ind2];
                ind++;
                ind2++;
            }
        }
        else ind2++;
    }
    for(int i=0; i<ind; i++)
    {
        printf("%d ", pass[i]);
    }
    printf("\n");
    return 0;
}
