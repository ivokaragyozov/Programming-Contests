/**
100 points
Ivo Karagyozov
*/
#include<iostream>
#include<algorithm>
using namespace std;
int boys[100], girls[100], n, m;
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>boys[i];
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>girls[i];
    }
    sort(boys, boys+n);
    sort(girls, girls+m);
    int indB=0, indG=0, ans=0;
    while(indB!=n && indG!=m)
    {
        int r=max(boys[indB], girls[indG])-min(boys[indB], girls[indG]);
        if(r==0 || r==1)
        {
            ans++;
            indB++;
            indG++;
        }
        else if(boys[indB]<girls[indG])
        {
            while(boys[indB]-girls[indG]<-1 && indB!=n)
            {
                indB++;
            }
            r=max(boys[indB], girls[indG])-min(boys[indB], girls[indG]);
            if(r==0 || r==1)
            {
                ans++;
                indB++;
                indG++;
            }
        }
        else
        {
            while(girls[indG]-boys[indB]<-1 && indG!=m)
            {
                indG++;
            }
            r=max(boys[indB], girls[indG])-min(boys[indB], girls[indG]);
            if(r==0 || r==1)
            {
                ans++;
                indB++;
                indG++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
