#include <iostream>
#define endl '\n'
using namespace std;

const int maxK = 1e5;

int n, k, p, r[maxK + 5], c[maxK + 5], x[maxK + 5], table[1000][1000], w, q, t, v, currXOR, currCnt, ind;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k>>p;
    for(int i = 0; i < k; i++)
    {
        cin>>r[i]>>c[i]>>x[i];
        table[r[i]][c[i]] = i;
    }
    for(int m = 0; m < p; m++)
    {
        cin>>w>>q>>t>>v;
        ind = table[w][q];
        r[ind] = t;
        c[ind] = v;
        table[w][q] = 0;
        table[t][v] = ind;

        currCnt = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                currXOR = 0;
                for(int q = 0; q < k; q++)
                {
                    if((r[q] == i && c[q] != j) || (r[q] != i && c[q] == j)) currXOR = currXOR ^ x[q];
                }

                if(currXOR != 0) currCnt++;
            }
        }

        cout<<currCnt<<endl;
    }

    return 0;
}
