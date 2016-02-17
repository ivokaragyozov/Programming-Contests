/**
Ivo Karagyozov
Zimni 2014 E1 busstop
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b=0;
    cin>>b;
    int br=1,sum=b,maxsum=0,maxbr=0;
    for(int i=2; i<n; i++)
    {
        cin>>a;
        if(a>b)
        {
            sum=sum+a;
            br++;
        }
        else
        {
            if(br>maxbr)
            {
                maxbr=br;
                maxsum=sum;
            }
            br=1;
            sum=a;
        }
        b=a;
    }
    if(br>maxbr)
    {
        maxbr=br;
        maxsum=sum;
        br=1;
        sum=a;
    }
    cout<<maxbr<<endl;
    int maxdel=0;
    for(int i=2; i<maxsum; i++)
    {
        if(maxsum%i==0)
        {
            maxdel=maxsum/i;
            break;
        }
    }
    cout<<maxdel<<endl;
    return 0;
}
