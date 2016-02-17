#include<iostream>
#include<cstdio>
using namespace std;
int a[10]={2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
int main()
{
    int n;
    scanf("%d", &n);
    int firstDig, secondDig;
    if(n<10)firstDig=0;
    else firstDig=n/10;
    secondDig=n%10;
    printf("%d\n", a[firstDig]*a[secondDig]);
    return 0;
}
