#include<iostream>
#include<queue>
using namespace std;

int n, k1, k2, a, br=0;
queue<int> p1, p2;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    cin>>k1;
    for(int i=0; i<k1; i++)
    {
        cin>>a;
        p1.push(a);
    }
    cin>>k2;
    for(int i=0; i<k2; i++)
    {
        cin>>a;
        p2.push(a);
    }
}

int main()
{
    input();
    while(1)
    {
        if(br==100000)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(p1.empty())
        {
            cout<<br<<" "<<2<<endl;
            return 0;
        }
        else if(p2.empty())
        {
            cout<<br<<" "<<1<<endl;
            return 0;
        }
        int c1=p1.front(), c2=p2.front();
        p1.pop();
        p2.pop();
        if(c1>c2)
        {
            p1.push(c2);
            p1.push(c1);
        }
        else
        {
            p2.push(c1);
            p2.push(c2);
        }
        br++;
    }
    return 0;
}
