/**
Ivo Karagyozov
Esenen 2009 C1 rich
*/
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int a, n, m;
priority_queue<int, vector<int>, cmp> piles;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a>>n;

    piles.push(a);

    while(cin>>m)
    {
        a = n;
        n = m;

        piles.push(a);
    }

    for(int i = 0; i < n; i++)
    {
        int cur = piles.top();
        piles.pop();

        cur++;

        piles.push(cur);
    }

    cout<<piles.top()<<endl;
    return 0;
}
