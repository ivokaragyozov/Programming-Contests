#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct peace
{
    int x1, y1, x2, y2;
};

int a, b, n;
queue<peace> qu;

int main()
{
    scanf("%d%d%d", &a, &b, &n);
    peace p;
    p.x1=0;
    p.y1=0;
    p.x2=b;
    p.y2=a;
    qu.push(p);
    for(int i=0; i<n; i++)
    {
        char type;
        int c;
        cin>>type>>c;
        long long siz=qu.size(), maxs=0;
        for(int j=0; j<siz; j++)
        {
            if(type=='H')
            {
                if(b-c>qu.front().x1 && b-c<qu.front().x2)
                {
                    peace p1, p2;
                    p1.x1=qu.front().x1;
                    p1.y1=qu.front().y1;
                    p1.x2=qu.front().x2-c;
                    p1.y2=qu.front().y2;
                    p2.x1=qu.front().x2-c;
                    p2.y1=qu.front().y1;
                    p2.x2=qu.front().x2;
                    p2.y2=qu.front().y2;
                    qu.push(p1);
                    qu.push(p2);
                    if((p1.x2-p1.x1)*(p1.y2-p1.y1)>maxs)maxs=(p1.x2-p1.x1)*(p1.y2-p1.y1);
                    if((p2.x2-p2.x1)*(p2.y2-p2.y1)>maxs)maxs=(p2.x2-p2.x1)*(p2.y2-p2.y1);
                }
                else
                {
                    qu.push(qu.front());
                    if((qu.front().x2-qu.front().x1)*(qu.front().y2-qu.front().y1)>maxs)maxs=(qu.front().x2-qu.front().x1)*(qu.front().y2-qu.front().y1);
                }
            }
            else
            {
                if(c>qu.front().y1 && c<qu.front().y2)
                {
                    peace p1, p2;
                    p1.x1=qu.front().x1;
                    p1.y1=qu.front().y1;
                    p1.x2=qu.front().x2;
                    p1.y2=c;
                    p2.x1=qu.front().x1;
                    p2.y1=c;
                    p2.x2=qu.front().x2;
                    p2.y2=qu.front().y2;
                    qu.push(p1);
                    qu.push(p2);
                    if((p1.x2-p1.x1)*(p1.y2-p1.y1)>maxs)maxs=(p1.x2-p1.x1)*(p1.y2-p1.y1);
                    if((p2.x2-p2.x1)*(p2.y2-p2.y1)>maxs)maxs=(p2.x2-p2.x1)*(p2.y2-p2.y1);
                }
                else
                {
                    qu.push(qu.front());
                    if((qu.front().x2-qu.front().x1)*(qu.front().y2-qu.front().y1)>maxs)maxs=(qu.front().x2-qu.front().x1)*(qu.front().y2-qu.front().y1);
                }
            }
            qu.pop();
        }
        printf("%I64d\n", maxs);
    }
    return 0;
}
