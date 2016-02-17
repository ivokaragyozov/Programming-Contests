/**
Ivo Karagyozov
NOI1 2014 E1 monkey
*/
#include<iostream>
using namespace std;
int d,m,g,n,k,x;
int mes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void nextday()
{
    if((g%4==0 && g%100!=0) || g%400==0)mes[2]=29;
    d++;
    if(d>mes[m])
    {
        d=1;
        m++;
        if(m>12)
        {
            m=1;
            g++;
        }
    }
    mes[2]=28;
}
int main()
{
    cin>>d>>m>>g>>n>>k>>x;
    int a=0;
    while(1)
    {
        a=a+k;
        if(a>=n)break;
        a=a-x;
        nextday();
    }
    cout<<d<<" "<<m<<" "<<g<<endl;
    return 0;
}
