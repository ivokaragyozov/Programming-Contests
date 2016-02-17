/**
Ivo Karagyozov
NOI3 2014 C6 magical
*/
#include<iostream>
#include<algorithm>
using namespace std;

int n1, n2, n3, n4, nmax=0, scarfs[100005], blouses[100005], genders[100005], shoes[100005], minr=1<<31-1, scarf, blouse, gender, shoe, ind1, ind2, ind3, ind4;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n1;
    if(n1>nmax)nmax=n1;
    for(int i=0; i<n1; i++)
    {
        cin>>scarfs[i];
    }
    sort(scarfs, scarfs+n1);
    cin>>n2;
    if(n2>nmax)nmax=n2;
    for(int i=0; i<n2; i++)
    {
        cin>>blouses[i];
    }
    sort(blouses, blouses+n2);
    cin>>n3;
    if(n3>nmax)nmax=n3;
    for(int i=0; i<n3; i++)
    {
        cin>>genders[i];
    }
    sort(genders, genders+n3);
    cin>>n4;
    if(n4>nmax)nmax=n4;
    for(int i=0; i<n4; i++)
    {
        cin>>shoes[i];
    }
    sort(shoes, shoes+n4);
    for(int i=0; i<nmax; i++)
    {
        int r=1<<31-1, a=scarfs[ind1], b=blouses[ind2], c=genders[ind3], d=shoes[ind4];
        if(max(a, b)-min(a, b)<r)r=max(a, b)-min(a, b);
        if(max(a, c)-min(a, c)<r)r=max(a, c)-min(a, c);
        if(max(a, d)-min(a, d)<r)r=max(a, d)-min(a, d);
        if(max(b, c)-min(b, c)<r)r=max(b, c)-min(b, c);
        if(max(b, d)-min(b, d)<r)r=max(b, d)-min(b, d);
        if(max(c, d)-min(c, d)<r)r=max(c, d)-min(c, d);
        if(r<minr)
        {
            minr=r;
            scarf=a;
            blouse=b;
            gender=c;
            shoe=d;
        }
        if(ind1!=n1-1)ind1++;
        if(ind2!=n2-1)ind2++;
        if(ind3!=n3-1)ind3++;
        if(ind4!=n4-1)ind4++;
    }
    cout<<scarf<<" "<<blouse<<" "<<gender<<" "<<shoe<<endl;
    return 0;
}
