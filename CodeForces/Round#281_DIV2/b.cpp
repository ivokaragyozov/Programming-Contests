#include<iostream>
#include<cstdio>
using namespace std;
long long wre1[200005], ind1=0, wre2[200005], ind2=0, sumWre1=0, sumWre2=0;
int main()
{
    int n, last=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        if(a>0)
        {
            wre1[ind1]=a;
            sumWre1+=a;
            ind1++;
            if(i==n-1)last=1;
        }
        else
        {
            wre2[ind2]=-a;
            sumWre2+=-a;
            ind2++;
            if(i==n-1)last=2;
        }
    }
    if(sumWre1!=sumWre2)
    {
        if(sumWre1<sumWre2)printf("%s\n", "second");
        else printf("%s\n", "first");
    }
    else
    {
        for(int i=0; i<min(ind1, ind2); i++)
        {
            if(wre1[i]>wre2[i])
            {
                printf("%s\n", "first");
                return 0;
            }
            else if(wre1[i]<wre2[i])
            {
                printf("%s\n", "second");
                return 0;
            }
        }
        if(last==1)printf("%s\n", "first");
        else printf("%s\n", "second");
    }
    return 0;
}
