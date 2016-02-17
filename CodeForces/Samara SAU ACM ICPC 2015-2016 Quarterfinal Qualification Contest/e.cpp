#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

struct card
{
    int c, r, ind, minInd1, minInd2;

    card(){}
    card(int c, int r, int ind)
    {
        this->c = c;
        this->r = r;
        this->ind = ind;
    }
};

bool p1 = true, p2 = true;
int n, a, b, ind = 1, minC = INT_MAX, minR = INT_MAX, currInd1, currInd2, startInd;
vector<int> path1, path2;
card cards[maxN];


bool cmp(card x, card y)
{
    if(x.r != y.r) return x.r < y.r;
    return x.c < y.c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;

        cards[ind++] = card(a, b, i + 1);
    }


    sort(cards + 1, cards + ind, cmp);

    for(int i = n; i >= 1; i--)
    {
        if(cards[i].c < minC)
        {
            minC = cards[i].c;
            currInd1 = i;
        }
        if(cards[i].r < minR)
        {
            minR = cards[i].r;
            currInd2 = i;
        }

        cards[i].minInd1 = currInd1;
        cards[i].minInd2 = currInd2;

        if(cards[i].ind == n) startInd = i;
    }

    for(int i = 1; i <= n; i++)
    {
        cout<<cards[i].c<<" "<<cards[i].r<<" "<<cards[i].ind<<" "<<cards[i].minInd1<<" "<<cards[i].minInd2<<endl;
    }


    currInd1 = startInd;
    currInd2 = startInd;
    path1.push_back(n);
    path2.push_back(n);
    while(cards[currInd1].c > 1 && cards[currInd2].c > 0)
    {
        if(!p1 && !p2)
        {
            cout<<"No such luck"<<endl;
            return 0;
        }

        if(p1)
        {
            if(cards[currInd1].minInd1 == currInd1) p1 = false;

            currInd1 = cards[currInd1].minInd1;
            path1.push_back(cards[currInd1].ind);
        }
        if(p2)
        {
            if(cards[currInd2].minInd2 == currInd2) p2 = false;

            currInd2 = cards[currInd2].minInd2;
            path2.push_back(cards[currInd2].ind);
        }
    }

    if(p1)
    {
        for(int i = path1.size() - 1; i >= 0; i--)
        {
            cout<<path1[i]<<" ";
        }
    }
    else
    {
        for(int i = path2.size() - 1; i >= 0; i--)
        {
            cout<<path2[i]<<" ";
        }
    }
    return 0;
}
