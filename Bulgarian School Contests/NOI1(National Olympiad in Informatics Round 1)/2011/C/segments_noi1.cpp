/**
Ivo Karagyozov
NOI1 2011 C1 segments
*/
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(b<a)swap(a, b);
    if(d<c)swap(c, d);
    if(c<a)
    {
        swap(a, c);
        swap(b, d);
    }
    int ans=0;
    if(a<=c && b>=d)
    {
        ans=d-c;
    }
    else if(a<=c && c<=b)
    {
        ans=b-c;
    }
    else
    {
        ans=-1;
    }
    printf("%d\n", ans);
    return 0;
}
