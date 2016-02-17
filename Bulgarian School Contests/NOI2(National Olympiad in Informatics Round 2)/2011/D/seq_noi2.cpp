/**
Ivo Karagyozov
NOI2 2011 D2 seq
*/
#include<iostream>
using namespace std;
int main()
{
    double a=-1,b;
    long long br=0,maxbr=0;
    while(a!=0)
    {
        b=a;
        cin>>a;
        if(a>=b)
        {
            br++;
        }
        else
        {
            if(br>maxbr)maxbr=br;
            br=1;
        }
    }
    if(br>maxbr)
    {
        maxbr=br;
    }
    cout<<maxbr<<endl;
    return 0;
}
