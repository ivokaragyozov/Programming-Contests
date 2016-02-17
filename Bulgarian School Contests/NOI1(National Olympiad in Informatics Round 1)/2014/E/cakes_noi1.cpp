/**
Ivo Karagyozov
NOI1 2014 E2 cakes
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct cake
{
    int d;
    int weight;
    int num;
};
int f1(cake s,cake t)
{
    if(s.d!=t.d)return s.d>t.d;
    else return t.weight>t.weight;
}
int main()
{
    cake a[3];
    for(int i=0;i<3;i++)
    {
        cin>>a[i].d>>a[i].weight;
        a[i].num=i+1;
    }
    sort(a,a+3,f1);
    for(int i=0;i<2;i++)
    {
        cout<<a[i].num<<" ";
    }
    cout<<a[2].num<<endl;
    return 0;
}
