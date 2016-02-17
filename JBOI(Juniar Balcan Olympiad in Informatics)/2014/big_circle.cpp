#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#define endl '\n'
const double eps = 0.00001;
using namespace std;

struct point
{
    double x, y, angle;

    point()
    {
        x=1<<30;
        y=1<<30;
        angle=1<<30;
    }
};

int n, ind_of_upper;
point p[100005], upper;
double d, mind=1<<30;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>p[i].x>>p[i].y;
        if(p[i].x<upper.x)
        {
            upper.x=p[i].x;
            upper.y=p[i].y;
            ind_of_upper=i;
        }
    }
}
bool cmp(point a, point b)
{
    if(abs(a.x-upper.x)<eps)return false;
    if(abs(b.x-upper.x)<eps)return true;
    return a.angle<b.angle;
}

int main()
{
    input();
    for(int i=0; i<n; i++)
    {
        if(i==ind_of_upper)
        {
            p[i].angle=0;
            continue;
        }
        p[i].angle=(p[i].x-upper.x)/(p[i].y-upper.y);
    }
    sort(p, p+n, cmp);
    for(int i=1; i<n; i++)
    {
        d=sqrt(pow(p[i-1].x-p[i].x, 2)+pow(p[i-1].y-p[i].y, 2));
        if(d<mind)
        {
            mind=d;
        }
    }
    d=sqrt(pow(p[0].x-p[n-1].x, 2)+pow(p[0].y-p[n-1].y, 2));
    if(d<mind)
    {
        mind=d;
    }
    printf("%.2lf\n", mind);
    return 0;
}
