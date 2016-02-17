/**
Ivo Karagyozov
NOI1 2015 B3 points
*/
#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

struct point
{
    int x, type, number;

    point(){}
    point(int x, int type, int number)
    {
        this->x=x;
        this->type=type;
        this->number=number;
    }
};

int n, m, x, y, ind=0, tbr=0, ans[100005];
point points[500000];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        if(x>y)swap(x, y);
        points[ind++]=point(x, 1, -1);
        points[ind++]=point(y, -1, -1);
    }
    for(int i=0; i<m; i++)
    {
        cin>>x;
        points[ind++]=point(x, 0, i);
    }
}
void output()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<ans[0];
    for(int i=1; i<m; i++)
    {
        cout<<" "<<ans[i];
    }
    cout<<endl;
}
bool cmp(point a, point b)
{
    if(a.x!=b.x)
    {
        return a.x<b.x;
    }
    return a.type>b.type;
}

int main()
{
    input();
    sort(points, points+ind, cmp);
    for(int i=0; i<ind; i++)
    {
        tbr+=points[i].type;
        if(points[i].type==0)
        {
            ans[points[i].number]=tbr;
        }
    }
    output();
    return 0;
}
