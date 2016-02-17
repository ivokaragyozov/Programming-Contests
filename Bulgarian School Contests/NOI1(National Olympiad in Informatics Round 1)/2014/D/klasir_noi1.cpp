/**
Ivo Karagyozov
NOI1 2014 D2 klasir
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct klasir
{
    int fin;
    int pos;
    int raz;
};
int f1(klasir s,klasir t)
{
    if(s.raz!=t.raz)return s.raz<t.raz;
    else return s.fin<t.fin;
}
int main()
{
    klasir a[6];
    for(int i=0;i<4;i++)
    {
        cin>>a[i].fin;
        a[i].pos=i+1;
    }
    for(int i=0;i<4;i++)
    {
        a[i].raz=a[i].pos-a[i].fin;
    }
    sort(a,a+4,f1);
    for(int i=0;i<3;i++)
    {
        cout<<a[i].fin<<" ";
    }
    cout<<a[3].fin<<endl;
    return 0;
}
