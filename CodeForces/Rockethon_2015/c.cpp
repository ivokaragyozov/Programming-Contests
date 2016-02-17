#include<iostream>
#include<cstdio>
using namespace std;
int br[10005];
int main()
{
    int n;
    scanf("%d", &n);
    int minb=10005, maxb=0;
    int r[5], l[5];
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &r[i], &l[i]);
        if(r[i]<minb)minb=r[i];
        if(l[i]>maxb)maxb=l[i];
    }
    int ind=0, brmax=0;
    for(int i=minb; i<=maxb; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i>=r[j] && i<=l[j])
            {
                br[ind]++;
                brmax++;
            }
        }
        cout<<i<<" "<<br[ind]<<endl;
        ind++;
    }
    cout<<brmax<<endl;
    double part=(100.0/brmax)/100.0, sum=0;
    cout<<part<<endl;
    for(int i=0; i<ind-1; i++)
    {
        sum+=br[i]*part*(minb+i);
    }
    printf("%f\n", sum);
    return 0;
}
