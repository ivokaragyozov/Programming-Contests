/**
Ivo Karagyozov
NOI2 2008 D1 ring
*/
#include<iostream>
#include<queue>
using namespace std;
int a[1000005];
int main()
{
    queue<int> q;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        q.push(i);
    }
    int prez=k;
    while(q.size()!=1)
    {
        for(int i=0;i<prez-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
        prez=a[q.front()];
        q.pop();
    }
    cout<<q.front()<<endl;
    return 0;
}
