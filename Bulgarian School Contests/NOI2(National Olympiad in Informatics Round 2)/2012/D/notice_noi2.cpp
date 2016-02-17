/**
Ivo Karagyozov
NOI2 2012 D2 notice
*/
#include<iostream>
using namespace std;
int tab[85][125];
int main()
{
    int a,b;
    cin>>a>>b;
    swap(a,b);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a1,b1,a2,b2;
        cin>>a1>>b1>>a2>>b2;
        swap(a1,b1);
        for(int j=a1;j<a1+b2;j++)
        {
            for(int k=b1;k<b1+a2;k++)
            {
                tab[j][k]=1;
            }
        }
    }
    int r,k,br=0;
    cin>>r>>k;
    swap(r,k);
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(i+r-1<a && j+k-1<b)
            {
                bool p=false;
                for(int x=i;x<=i+r-1;x++)
                {
                    if(p==true)break;
                    for(int y=j;y<=j+k-1;y++)
                    {
                        if(tab[x][y]==1)
                        {
                            p=true;
                            break;
                        }
                    }
                }
                if(p==false)
                {
                    br++;
                }
            }
        }
    }
    cout<<br<<endl;
    return 0;
}
