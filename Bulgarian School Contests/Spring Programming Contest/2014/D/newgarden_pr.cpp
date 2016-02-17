/**
Ivo Karagyozov
Proleten 2014 D3 newgarden
*/
#include<iostream>
using namespace std;
int a[205][205];
int br=0;
int n,m;
void bigsize(int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m || a[i][j]==1)
    {
        return;
    }
    br++;
    a[i][j]=1;
    bigsize(i+1,j);
    bigsize(i-1,j);
    bigsize(i,j+1);
    bigsize(i,j-1);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int maxbr=0,maxpl=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)
            {
                br=0;
                bigsize(i,j);
                if(br>maxbr)
                {
                    maxbr=br;
                    maxpl=1;
                }
                else if(br==maxbr)
                {
                    maxpl++;
                }
            }
        }
    }
    cout<<maxbr<<" "<<maxpl<<endl;
    return 0;
}
