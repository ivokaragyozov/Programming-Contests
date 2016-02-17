/**
Ivo Karagyozov
NOI3 2009 D2 clock
*/
#include<iostream>
using namespace std;
int h,m;
int a[15]={0,5,10,16,21,27,32,38,43,49,54};
void nextmoment(int &h,int &m)
{
    m++;
    if(m==60)
    {

        m=0;
        h++;
        if(h==12)
        {
            h=0;
        }
    }
}
int main()
{
    cin>>h>>m;
    int brm=0;
    while(1)
    {
        bool p=false;
        for(int i=0;i<11;i++)
        {
            if(h==i && m==a[i])
            {
                p=true;
                break;
            }
        }
        if(p==true)break;


        brm++;
        nextmoment(h,m);
    }
    cout<<brm<<endl;
    return 0;
}
