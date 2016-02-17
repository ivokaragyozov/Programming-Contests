/**
Ivo Karagyozov
NOI1 2012 C2 number
*/
#include<iostream>
#include<cstdio>
using namespace std;
bool isInSet(long long num)
{
    int a=num/10000;
    int b=num/1000%10;
    int c=num/100%10;
    int d=num/10%10;
    int e=num%10;
    if(b==a+c && d==c+e)return true;
    return false;
}
int main()
{
    long long num;
    scanf("%lld", &num);
    if(isInSet(num)==false)
    {
        printf("0\n");
        return 0;
    }
    int number=0;
    for(int i=10000; i<=num; i++)
    {
        if(isInSet(i)==true)number++;
    }
    printf("%d\n", number);
    return 0;
}
