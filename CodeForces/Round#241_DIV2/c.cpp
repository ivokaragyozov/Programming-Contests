#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int maxN = 1005, maxK = 1005;

struct table
{
    int sizeOfTable, ind;
};

bool vis[maxN];
int n, k, c[maxN], p[maxN], taken[maxN], tab[maxN], ind, currMax, ans, takenInd;
table tables[maxK];

bool cmp(table x, table y)
{
    return x.sizeOfTable < y.sizeOfTable;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>c[i]>>p[i];
    }

    cin>>k;
    for(int i = 0; i < k; i++)
    {
        cin>>tables[i].sizeOfTable;

        tables[i].ind = i;
    }

    sort(tables, tables + k, cmp);

    for(int i = 0; i < k; i++)
    {
        currMax = 0;

        for(int j = 0; j < n; j++)
        {
            if(c[j] <= tables[i].sizeOfTable && p[j] > currMax && !vis[j])
            {
                currMax = p[j];
                takenInd = j;
            }
        }


        if(currMax == 0) continue;

        vis[takenInd] = true;
        ans += currMax;
        taken[ind] = takenInd + 1;
        tab[ind++] = tables[i].ind + 1;
    }

    cout<<ind<<" "<<ans<<endl;
    for(int i = 0; i < ind; i++)
    {
        cout<<taken[i]<<" "<<tab[i]<<endl;
    }
    return 0;
}
