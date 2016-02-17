/**
Ivo Karagyozov
NOI2 2010 C2 box
*/
#include<iostream>
#include<cstdio>
using namespace std;

int w[6], h[6], sides[3]={1, 1, 1}, ind=0, br=0;
bool used[6];

int main()
{
    for(int i=0; i<6; i++)
    {
        scanf("%d%d", &w[i], &h[i]);
        if(w[i]>h[i])swap(w[i], h[i]);
        bool p=false, k=false;
        for(int j=0; j<ind; j++)
        {
            if(sides[j]==w[i])p=true;
            if(sides[j]==h[i])k=true;
        }
        if(p==false)
        {
            sides[ind]=w[i];
            ind++;
        }
        if(k==false)
        {
            sides[ind]=h[i];
            ind++;
        }
    }
    for(int i=0; i<6; i++)
    {
        if(used[i]==true)continue;
        used[i]=true;
        for(int j=i+1; j<6; j++)
        {
            if(w[i]==w[j] && h[i]==h[j] && used[j]==false)
            {
                br++;
                used[j]=true;
                break;
            }
        }
    }
    if(br==3)
    {
        printf("%d\n", sides[0]*sides[1]*sides[2]);
    }
    else printf("%d\n", 0);
    return 0;
}
