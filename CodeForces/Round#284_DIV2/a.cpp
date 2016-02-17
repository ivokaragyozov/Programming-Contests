#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int currentMin=1, brMins=0;
    for(int i=0; i<n; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        while(1)
        {
            if(currentMin+x<=l)currentMin+=x;
            else
            {
                brMins+=r-currentMin+1;
                currentMin=r+1;
                break;
            }
        }
    }
    printf("%d\n", brMins);
    return 0;
}
