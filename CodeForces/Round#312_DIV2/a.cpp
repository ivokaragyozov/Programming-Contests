#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

struct tree
{
    int ind, cntApples;

    tree(){}
    tree(int ind, int cnt)
    {
        this->ind = ind;
        cntApples = cnt;
    }
};

int n, coor, cntApples;
vector<tree> rightApples, leftApples;
int answer = 0;

bool cmp1(tree a, tree b)
{
    if(a.ind != b.ind) return a.ind < b.ind;
    else return a.cntApples > b.cntApples;
}
bool cmp2(tree a, tree b)
{
    if(a.ind != b.ind) return a.ind > b.ind;
    else return a.cntApples > b.cntApples;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>coor>>cntApples;
        if(coor < 0)
        {
            leftApples.push_back(tree(coor, cntApples));
        }
        else
        {
            rightApples.push_back(tree(coor, cntApples));
        }
    }

    sort(rightApples.begin(), rightApples.end(), cmp1);
    sort(leftApples.begin(), leftApples.end(), cmp2);

    int i;
    for(i = 0; i < min(rightApples.size(), leftApples.size()); i++)
    {
        answer += rightApples[i].cntApples+leftApples[i].cntApples;
    }
    if(rightApples.size() < leftApples.size())
    {
        answer += leftApples[i].cntApples;
    }
    else if(rightApples.size() > leftApples.size())
    {
        answer += rightApples[i].cntApples;
    }

    cout<<answer<<endl;
    return 0;
}
