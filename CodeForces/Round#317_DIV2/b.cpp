#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

struct order
{
    int p, q;

    order(){}
    order(int p, int q)
    {
        this->p = p;
        this->q = q;
    }
};

char type;
int n, s, p, q, startInd, endInd;
map<int, int> buy, sell;
vector<order> buyOrders, sellOrders;

bool cmp(order a, order b)
{
    return a.p > b.p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>s;
    for(int i = 0; i < n; i++)
    {
        cin>>type>>p>>q;

        if(type == 'S') sell[p] += q;
        else buy[p] += q;
    }

    for(map<int, int>::iterator i = buy.begin(); i != buy.end(); i++)
    {
        buyOrders.push_back(order(i->first, i->second));
    }
    for(map<int, int>::iterator i = sell.begin(); i != sell.end(); i++)
    {
        sellOrders.push_back(order(i->first, i->second));
    }

    sort(buyOrders.begin(), buyOrders.end(), cmp);
    sort(sellOrders.begin(), sellOrders.end(), cmp);

    if(sell.size() <= s) startInd = 0;
    else startInd = sell.size()-s;

    for(int i = startInd; i < sell.size(); i++)
    {
        cout<<"S "<<sellOrders[i].p<<" "<<sellOrders[i].q<<endl;
    }

    if(buy.size() <= s) endInd = buy.size()-1;
    else endInd = s-1;

    for(int i = 0; i <= endInd; i++)
    {
        cout<<"B "<<buyOrders[i].p<<" "<<buyOrders[i].q<<endl;
    }

    return 0;
}
