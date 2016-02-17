/**
Ivo Karagyozov
NOI1 2013 C1 fibseq
*/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n, a, b, c;
    scanf("%d %d %d", &n, &b, &c);
    a=c-b;
    while(n>1)
    {
        c=b;
        b=a;
        a=c-b;
        n--;
    }
    printf("%d %d\n", b, c);
    return 0;
}
