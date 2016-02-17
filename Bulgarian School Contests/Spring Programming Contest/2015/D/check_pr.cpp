/**
Ivo Karagyozov
Proleten 2015 C2 check
*/
#include <iostream>
#define endl '\n'
using namespace std;

int n, m, x1, y1, x2, y2, tx, ty;
char pos_of_screen;
string moves;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>x1>>y1>>moves;
    swap(x1, y1);
}

int main()
{
    input();
    tx=x1;
    ty=y1;
    if(x1==1 && y1==1)
    {
        x2=n;
        y2=m;
    }
    else if(x1==1 && y1==m)
    {
        x2=n;
        y2=1;
    }
    else if(x1==n && y1==1)
    {
        x2=1;
        y2=m;
    }
    else
    {
        x2=1;
        y2=1;
    }
    pos_of_screen='U';
    for(int i=0; i<moves.size(); i++)
    {
        if(moves[i]=='U')
        {
            tx++;
            if(tx==n+1)
            {
                cout<<"NO"<<endl;
                cout<<i+1<<endl;
                return 0;
            }
            if(pos_of_screen=='U')
            {
                pos_of_screen='N';
            }
            else if(pos_of_screen=='S')
            {
                pos_of_screen='U';
            }
            else if(pos_of_screen=='N')
            {
                cout<<"NO"<<endl;
                cout<<i+1<<endl;
                return 0;
            }
        }
        else if(moves[i]=='R')
        {
            ty++;
            if(ty==m+1)
            {
                cout<<"NO"<<endl;
                cout<<i+1<<endl;
                return 0;
            }
            if(pos_of_screen=='U')
            {
                pos_of_screen='E';
            }
            else if(pos_of_screen=='W')
            {
                pos_of_screen='U';
            }
            else if(pos_of_screen=='E')
            {
                cout<<"NO"<<endl;
                cout<<i+1<<endl;
                return 0;
            }
        }
        else if(moves[i]=='D')
        {
            tx--;
            if(tx==0)
            {
                cout<<"NO"<<endl;
                cout<<i+1<<endl;
                return 0;
            }
            if(pos_of_screen=='U')
            {
                pos_of_screen='S';
            }
            else if(pos_of_screen=='N')
            {
                pos_of_screen='U';
            }
            else if(pos_of_screen=='S')
            {
                cout<<"NO"<<endl;
                cout<<i+1<<endl;
                return 0;
            }
        }
        else
        {
            ty--;
            if(ty==0)
            {
                cout<<"NO"<<endl;
                cout<<i+1<<endl;
                return 0;
            }
            if(pos_of_screen=='U')
            {
                pos_of_screen='W';
            }
            else if(pos_of_screen=='E')
            {
                pos_of_screen='U';
            }
            else if(pos_of_screen=='W')
            {
                cout<<"NO"<<endl;
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
    if(tx!=x2 || ty!=y2 || pos_of_screen!='U')
    {
        cout<<"NO"<<endl;
        cout<<-1<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}
