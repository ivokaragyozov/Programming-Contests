#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105;

struct action
{
    int time, type;

    action(){}
    action(int time, int type)
    {
        this->time = time;
        this->type = type;
    }
};

int t, n, beg, en, ind, ans, curr;
action actions[2 * maxN];

bool cmp(action x, action y)
{
    return x.time < y.time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        ans = 0;
        curr = 0;
        ind = 0;

        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>beg>>en;

            actions[ind++] = action(beg, 0);
            actions[ind++] = action(en, 1);
        }

        sort(actions, actions + ind, cmp);

        for(int i = 0; i < ind; i++)
        {
            if(actions[i].type == 0) curr++;
            else curr--;

            if(curr > ans) ans = curr;
        }

        cout<<ans<<endl;
    }
}
