#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long a, b;
    scanf("%I64d %\I64d", &a, &b);
    if(b==a)
    {
        printf("%s\n", "infinity");
        return 0;
    }
    long long br=0, c=0;
    c=a-b;
    for(long long i=1; i<=c; i++)
    {
        if(c%i==0 && a%i==b)
        {
            br++;
        }
    }
    /*for(long long i=c; i<=a; i+=c)
    {
        if(a%i==b)
        {
            br++;
            cout<<i<<endl;
        }
    }*/
    /*long long sum=0, i;
    for(i=1; sum<=raz; i++)
    {
        sum+=c;
        c=2*c;
        cout<<sum<<" "<<i<<" "<<c<<endl;
    }*/
    printf("%I64d\n", br);
    return 0;
}
