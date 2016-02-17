/**
Ivo Karagyozov
Esenen 2010 D1 seq
*/
#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
bool isDiff(int i)
{
    int n[4]={a[i-3], a[i-2], a[i-1], a[i]};
    sort(n, n+4);
    if(n[0]==1 && n[1]==2 && n[2]==4 && n[3]==8)return true;
    return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int maxBr=0, br=1;
    for(int i=1; i<n; i++)
    {
        if(a[i-1]==a[i])br++;
        else
        {
            if(br>maxBr)maxBr=br;
            br=1;
        }
    }
    if(br>maxBr)maxBr=br;
    cout<<maxBr<<" ";
    br=0;
    for(int i=3; i<n; i++)
    {
        if(isDiff(i)==true)br++;
    }
    cout<<br<<endl;
    return 0;
}
