#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;
const long double pi = atan(1.0) * 4;

struct point
{
    int x, y, ind;
    long double dist;

    point(){}
    point(int a, int b, int c)
    {
        x = a;
        y = b;
        ind = c;
        dist = sqrt((double)x * x + y * y);
    }
};

int n, a, b, ind, ind1, ind2;
long double minAngle = 5000;
point points[maxN], center = point(0, 0, 1000000);

bool cmp(point a, point b)
{
    if (a.x - center.x >= 0 && b.x - center.x < 0)
        return true;
    if (a.x - center.x < 0 && b.x - center.x >= 0)
        return false;
    if (a.x - center.x == 0 && b.x - center.x == 0) {
        if (a.y - center.y >= 0 || b.y - center.y >= 0)
            return a.y > b.y;
        return b.y > a.y;
    }

    int det = (a.x - center.x) * (b.y - center.y) - (b.x - center.x) * (a.y - center.y);
    if (det < 0)
        return true;
    if (det > 0)
        return false;

    int d1 = (a.x - center.x) * (a.x - center.x) + (a.y - center.y) * (a.y - center.y);
    int d2 = (b.x - center.x) * (b.x - center.x) + (b.y - center.y) * (b.y - center.y);
    return d1 > d2;
}
long double prd_vect(point u, point v)
{
    return (double)u.x*v.y - u.y*v.x;
}
long double angle_rad(point u, point v)
{
   return (double)(prd_vect(u,v)<0 ? -1:1) * acos((u.x * v.x + u.y * v.y) / (u.dist*v.dist));
}
long double angle_deg(point u, point v)
{
   return (double)angle_rad(u,v) / pi * 180 ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;

        points[ind++] = point(a, b, ind);
    }


    sort(points, points + ind, cmp);

    for(int i = 0; i < ind; i++)
    {
        int last = (i == 0 ? ind - 1 : i - 1);
        long double angle = abs(angle_deg(points[i], points[last]));


        if(angle <= minAngle)
        {
            minAngle = angle;
            ind1 = points[i].ind;
            ind2 = points[last].ind;
        }
    }

    cout<<ind1<<" "<<ind2<<endl;
    return 0;
}
