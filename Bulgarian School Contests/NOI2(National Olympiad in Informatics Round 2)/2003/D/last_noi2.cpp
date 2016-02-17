/**
Ivo Karagyozov
NOI2 2003 D2 last
*/
#include<iostream>
using namespace std;
bool a[1005][1005];
int main()
{
    int n,m;
    cin>>n>>m;
    int i=1,j=1;
    int pos=2;
    a[1][1]=true;
    while(1)
    {
        if(pos==1)
        {
            if(i-1>=1 && a[i-1][j]==false)
            {
                i--;
            }
            else pos=2;
        }
        else if(pos==2)
        {
            if(j+1<=n && a[i][j+1]==false)
            {
                j++;
            }
            else pos=3;
        }
        else if(pos==3)
        {
            if(i+1<=m && a[i+1][j]==false)
            {
                i++;
            }
            else pos=4;
        }
        else
        {
            if(j-1>=1 && a[i][j-1]==false)
            {
                j--;
            }
            else pos=1;
        }
        a[i][j]=true;
        if((i+1>n || a[i+1][j]==true) && (i-1<1 || a[i-1][j]==true) && (j+1>m || a[i][j+1]==true) && (j-1<1 || a[i][j-1]==true))break;
    }
    cout<<"("<<j<<","<<i<<")"<<endl;
    return 0;
}
