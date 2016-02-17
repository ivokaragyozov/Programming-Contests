#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct triangles
{
    int be, en;
};

int n, br=0;
triangles t[1005];

int cmp(triangles a, triangles b)
{
    return a.be<b.be;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &t[i].be, &t[i].en);
        t[i].en+=t[i].be;
    }
    sort(t, t+n, cmp);
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("%d %d\n", t[i].be, t[i].en);
    }
    int be=-1, en=-1;
    for(int i=0; i<n; i++)
    {
        if(t[i].en>en)
        {
            br++;
        }
        if(t[i].be==en)br++;
        be=t[i].be;
        en=t[i].en;
    }
    printf("%d\n", br);
    return 0;
}
