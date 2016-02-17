/**
Ivo Karagyozov
Esenen 2012 D3 board
*/
#include<iostream>
using namespace std;
int main()
{
    int board[5][6],a,b,c,d,k;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>board[i][j];
            if(board[i][j]==1)
            {
                a=i;
                b=j;
            }
        }
    }
    for(int i=2;i<=20;i++)
    {
        bool p=false;
        if(a-2>=1 && b+1<=5)
        {
            if(board[a-2][b+1]==i)
            {
                p=true;
                c=a-2;
                d=b+1;
            }
        }
        if(a-2>=1 && b-1>=1)
        {
            if(board[a-2][b-1]==i)
            {
                p=true;
                c=a-2;
                d=b-1;
            }
        }
        if(a+2<=4 && b+1<=5)
        {
            if(board[a+2][b+1]==i)
            {
                p=true;
                c=a+2;
                d=b+1;
            }
        }
        if(a+2<=4 && b-1>=1)
        {
            if(board[a+2][b-1]==i)
            {
                p=true;
                c=a+2;
                d=b-1;
            }
        }
        if(a+1<=4 && b+2<=5)
        {
            if(board[a+1][b+2]==i)
            {
                p=true;
                c=a+1;
                d=b+2;
            }
        }
        if(a-1>=1 && b+2<=5)
        {
            if(board[a-1][b+2]==i)
            {
                p=true;
                c=a-1;
                d=b+2;
            }
        }
        if(a+1<=4 && b-2>=1)
        {
            if(board[a+1][b-2]==i)
            {
                p=true;
                c=a+1;
                d=b-2;
            }
        }
        if(a-1>=1 && b-2>=1)
        {
            if(board[a-1][b-2]==i)
            {
                p=true;
                c=a-1;
                d=b-2;
            }
        }
        if(p==false)
        {
            k=i-1;
            break;
        }
        if(i==20 && p==true)
        {
            cout<<20<<endl;
            return 0;
        }
        a=c;
        b=d;
    }
    cout<<k<<endl;
}
