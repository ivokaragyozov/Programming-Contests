#include<iostream>
using namespace std;

int iBeg, jBeg, n, m;
char Beg, a[50][50];
bool p=false, b[50][50], k=false;

void dfs(int i, int j, int last)
{
    if(!(i==iBeg && j==jBeg))b[i][j]=true;
    if(p==true)return;
    if(i!=0 && a[i-1][j]==Beg && b[i-1][j]==false && last!=3)
    {
        if(i-1==iBeg && j==jBeg && last!=3)
        {
            p=true;
            return;
        }
        dfs(i-1, j, 1);
    }
    if(j!=m-1 && a[i][j+1]==Beg && b[i][j+1]==false && last!=4)
    {
        if(i==iBeg && j+1==jBeg && last!=4)
        {
            p=true;
            return;
        }
        dfs(i, j+1, 2);
    }
    if(i!=n-1 && a[i+1][j]==Beg && b[i+1][j]==false && last!=1)
    {
        if(i+1==iBeg && j==jBeg && last!=1)
        {
            p=true;
            return;
        }
        dfs(i+1, j, 3);
    }
    if(j!=0 && a[i][j-1]==Beg && b[i][j-1]==false && last!=2)
    {
        if(i==iBeg && j-1==jBeg && last!=2)
        {
            p=true;
            return;
        }
        dfs(i, j-1, 4);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int p=0; p<n; p++)
            {
                for(int k=0; k<m; k++)
                {
                    b[p][k]=false;
                }
            }
            iBeg=i;
            jBeg=j;
            Beg=a[i][j];
            k=false;
            dfs(i, j, 0);
            if(p==true)break;

        }
        if(p==true)break;
    }
    if(p==true)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
