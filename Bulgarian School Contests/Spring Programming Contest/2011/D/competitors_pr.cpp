/**
Ivo Karagyozov
Proleten 2011 D1 competitors
*/
#include<iostream>
#include<algorithm>
using namespace std;
bool p[25],q[15];
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[15];
    int temi[15][20],maxt=0,t=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>maxt)
        {
            maxt=a[i];
            t=i;
        }
        for(int j=0;j<a[i];j++)
        {
            cin>>temi[i][j];
        }
    }
    q[t]=true;
    int comp[15],j=0;
    for(int i=0;i<a[t];i++)
    {
        p[temi[t][i]]=true;
    }
    comp[j]=t+1;
    j++;
    int brt=a[t];
    while(brt<k)
    {
        int maxbr=0,s=0;
        for(int i=0;i<n;i++)
        {
            if(q[i]==false)
            {
                int br=0;
                for(int j=0;j<a[i];j++)
                {
                    if(p[temi[i][j]]==false)
                    {
                        br++;
                    }
                }
                if(br>maxbr)
                {
                    maxbr=br;
                    s=i;
                }
            }
        }
        for(int i=0;i<a[s];i++)
        {
            p[temi[s][i]]=true;
        }
        q[s]=true;
        comp[j]=s+1;
        j++;
        brt=brt+maxbr;
    }
    sort(comp,comp+j);
    cout<<j<<endl;
    for(int i=0;i<j-1;i++)
    {
        cout<<comp[i]<<" ";
    }
    cout<<comp[j-1]<<endl;
    return 0;
}
