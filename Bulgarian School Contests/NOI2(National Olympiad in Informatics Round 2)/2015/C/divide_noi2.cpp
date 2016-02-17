/**
Ivo Karagyozov
NOI2 2015 C1 divide
*/
#include<iostream>
#include<cstdio>
using namespace std;

int pows[31]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
int n, a, b, needs[30], sum=0;

int binaryS(int target)
{
    int le=0, ri=30;
    while(le<=ri)
    {
        int mid=(le+ri)/2;
        if(target>pows[mid])
        {
            le=mid+1;
        }
        else if(target<pows[mid])
        {
            ri=mid-1;
        }
        else return mid;
    }
    return ri;
}
void numbysums(int m)
{
    while(m>0)
    {
        int c=binaryS(m);
        m-=pows[c];
        needs[c]++;
    }
}

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    numbysums(a);
    numbysums(b);
    numbysums(pows[n]-a-b);
    for(int i=0; i<n; i++)
    {
        sum+=needs[i];
    }
    printf("%d\n", sum-1);
    return 0;
}
