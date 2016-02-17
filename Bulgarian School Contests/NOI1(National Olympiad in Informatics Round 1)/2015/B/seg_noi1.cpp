/**
Ivo Karagyozov
NOI1 2015 B2 seg
*/
#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

struct point
{
    int x;
    bool type;

    point(){}
    point(int x, bool type)
    {
        this->x=x;
        this->type=type;
    }
};

int n, be, en, ind=0, tlen=0, maxlen=0, tbr=0, br=0, lastind=0;
point points[2005];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>be>>en;
        points[ind++]=point(be, 0);
        points[ind++]=point(en, 1);
    }
}
void output()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<br<<" "<<maxlen<<endl;
}
bool cmp(point a, point b)
{
    if(a.x!=b.x)
    {
        return a.x<b.x;
    }
    return a.type<b.type;
}

int main()
{
    input();
    sort(points, points+ind, cmp);
    lastind=points[0].x;
    for(int i=0; i<ind; i++)
    {
        if(points[i].type==0)
        {
            tbr++;
        }
        else
        {
            tbr--;
        }
        tlen++;
        if(tbr==0)
        {
            br++;
            tlen=points[i].x-lastind;
            if(tlen>maxlen)
            {
                maxlen=tlen;
            }
            if(i+1<ind)lastind=points[i+1].x;
        }
    }
    output();
    return 0;
}
