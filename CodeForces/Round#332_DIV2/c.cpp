#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

struct castle
{
    int h, ind;

    castle(){}
    castle(int h, int ind)
    {
        this->h = h;
        this->ind = ind;
    }
};

int n, a, answer, curr, w, z, f;
castle castles[maxN];
vector<int> currMax;

bool cmp(castle x, castle y)
{
    if(x.h != y.h) return x.h < y.h;
    return x.ind < y.ind;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;

        castles[i] = castle(a, i);
    }

    sort(castles, castles + n, cmp);


    int k = 0, p = 0;
    for(int i = 0; i < n; i++)
    {
        if(currMax.size() != 0 && castles[i].ind < currMax[currMax.size() - 1])
        {
            while(i < n && castles[i].ind < currMax[currMax.size() - 1])
            {
                for(int j = 0; j < currMax.size(); j++)
                {
                    if(j == k)
                    {
                        p = k + 1;
                        break;
                    }

                    if(currMax[j] > castles[i].ind)
                    {
                        p = j;
                        break;
                    }
                }


                if(p < k) k = p;
                i++;
            }
            answer += k + 1;
            k = 0;
            i--;
            currMax.erase(currMax.begin(), currMax.end());
        }
        else
        {
            k++;
            currMax.push_back(castles[i].ind);
        }
    }




    answer += k;

    cout<<answer<<endl;
    return 0;
}
