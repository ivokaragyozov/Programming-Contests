#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 105;

struct child
{
    int cntTimes, ind;
};

int n, m, a;
child childs[maxN];

bool cmp(child x, child y)
{
    if(x.cntTimes != y.cntTimes) return x.cntTimes < y.cntTimes;
    else return x.ind < y.ind;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        childs[i].ind = i;
        if(a % m == 0) childs[i].cntTimes = a / m;
        else childs[i].cntTimes = a / m + 1;
    }

    sort(childs, childs + n, cmp);

    cout<<childs[n - 1].ind + 1<<endl;
    return 0;
}
