/**
Ivo Karagyozov
Proleten 2010 C1 game
*/
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

int n, p;
long long a, b;
queue<long long> q1, q2;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    p=pow(2, 2*n);
    for(int i=0; i<p; i++)
    {
        cin>>a;
        q1.push(a);
    }
}

int main()
{
    input();
    for(int i=2*n-1; i>=0; i--)
    {
        if(q1.empty())
        {
            while(!q2.empty())
            {
                a=q2.front();
                q2.pop();
                b=q2.front();
                q2.pop();
                q1.push(max(a, b));
            }
        }
        else
        {
            while(!q1.empty())
            {
                a=q1.front();
                q1.pop();
                b=q1.front();
                q1.pop();
                q2.push(min(a, b));
            }
        }
    }
    cout<<q1.front()<<endl;
    return 0;
}
