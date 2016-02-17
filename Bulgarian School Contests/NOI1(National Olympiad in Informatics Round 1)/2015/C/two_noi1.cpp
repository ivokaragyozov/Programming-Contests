/**
Ivo Karagyozov
NOI1 2015 C3 two
*/
#include<iostream>
#include<cstdio>
using namespace std;
int cycle[365];
int main()
{
    int beg1, en1, beg2, en2;
    scanf("%d %d %d %d", &beg1, &en1, &beg2, &en2);
    for(int i=beg1; i!=(en1+1)%360; i++)
    {
        i=i%360;
        cycle[i]=1;
    }
    if(beg1==en1)cycle[beg1]=1;
    bool p=false;
    for(int j=beg2; j!=(en2+1)%360; j++)
    {
        j=j%360;
        if(cycle[j]==1)
        {
            p=true;
            break;
        }
    }
    if(beg2==en2)
    {
        if(cycle[beg2]==1)p=true;
    }
    cout<<p<<endl;
    return 0;
}
