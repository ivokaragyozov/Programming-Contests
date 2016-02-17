#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const double pi = 3.1415926, eps = 0.0000001;

double n, x, y, a, b, minDist = -1, maxDist, currDist, c;

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double area(double r)
{
    return pi * r * r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>a>>b;
    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;

        currDist = dist(a, b, x, y);
        if(currDist + eps > maxDist) maxDist = currDist;
        if(currDist - eps < minDist || minDist == -1) minDist = currDist;
    }


    cout<<fixed<<setprecision(7);
    if(maxDist == minDist) cout<<area(maxDist)<<endl;
    else cout<<area(maxDist) - area(minDist)<<endl;
    return 0;
}
