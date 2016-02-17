/**
Ivo Karagyozov
Esenen 2011 C1 triangles
*/
#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

struct point
{
    char name;
    int x, y;

    point(){}
    point(char name, int x, int y)
    {
        this->name = name;
        this->x = x;
        this->y = y;
    }
};

bool hasTriangles = false;
int n, x, y;
char ch;
point points[30];

bool isPos(point a, point b, point c)
{
    int x1 = a.x-b.x, y1 = a.y-b.y, x2 = a.x-c.x, y2 = a.y-c.y;

    if(x1*y2 == x2*y1) return false;
    else return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>ch>>x>>y;

        points[i] = point(ch, x, y);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int p = j+1; p < n; p++)
            {
                if(isPos(points[i], points[j], points[p]))
                {
                    hasTriangles = true;
                    cout<<points[i].name<<" "<<points[j].name<<" "<<points[p].name<<endl;
                }
            }
        }
    }

    if(!hasTriangles) cout<<"No triangles."<<endl;
    return 0;
}
