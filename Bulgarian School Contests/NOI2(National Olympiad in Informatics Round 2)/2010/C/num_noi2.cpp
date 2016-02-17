/**
Ivo Karagyozov
NOI2 2010 C1 nums
*/
#include<iostream>
#include<cstdio>
using namespace std;

int a, b, br=0;

bool difnums(int a)
{
    bool used[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(a>0)
    {
        if(used[a%10]==1)return false;
        used[a%10]=1;
        a/=10;
    }
    return true;
}

int main()
{
    scanf("%d%d", &a, &b);
    for(int i=a; i<=b; i++)
    {
        if(difnums(i)==true)br++;
    }
    printf("%d\n", br);
    return 0;
}
