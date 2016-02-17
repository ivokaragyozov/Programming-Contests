#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 2e6 + 5;

struct action
{
    int point;
    char type;

    action(){}
    action(int point, char type)
    {
        this->point = point;
        this->type = type;
    }
};
struct section
{
    int st, en;

    section(){}
    section(int st, int en)
    {
        this->st = st;
        this->en = en;
    }
};

bool p;
int n, k, a, b, ind, cnt, ind2;
action actions[2 * maxN];
section sections[2 * maxN];

bool cmp(action x, action y)
{
    if(x.point != y.point) return x.point < y.point;
    else return x.type < y.type;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;
        actions[ind++] = action(a, 'b');
        actions[ind++] = action(b, 'e');
    }

    sort(actions, actions + ind, cmp);

    for(int i = 0; i < ind; i++)
    {
        if(actions[i].type == 'b') cnt++;
        else cnt--;

        if(cnt >= k)
        {
            if(!p)
            {
                //cout<<actions[i].point<<endl;
                sections[ind2].st = actions[i].point;
                p = true;
            }
        }
        else
        {
            if(p)
            {
                sections[ind2++].en = actions[i].point;
                p = false;
            }
        }
    }

    cout<<ind2<<endl;
    for(int i = 0; i < ind2; i++)
    {
        cout<<sections[i].st<<" "<<sections[i].en<<endl;
    }

    return 0;
}
