#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

struct node
{
    long long val, le, ri, lazy;
    node *leftNode, *rightNode;

    node()
    {
        val = 0;
        lazy = 0;
        leftNode = NULL;
        rightNode = NULL;
    }
};

long long t, n, q, type, x, y, v;
node *root = new node();

void buildTree(node *currNode, long long le, long long ri)
{
    currNode->le = le;
    currNode->ri = ri;

    if(le == ri) return;

    currNode->leftNode = new node();
    currNode->rightNode = new node();

    long long mid = (le + ri) / 2;
    buildTree(currNode->leftNode, le, mid);
    buildTree(currNode->rightNode, mid + 1, ri);

    currNode->val = currNode->leftNode->val + currNode->rightNode->val;
}
void updateRange(node *currNode, long long left, long long right, long long newVal)
{
    long long le = currNode->le, ri = currNode->ri;

    if(currNode->lazy != 0)
    {
        currNode->val += (ri - le + 1) * currNode->lazy;

        if(le != ri)
        {
            currNode->leftNode->lazy += currNode->lazy;
            currNode->rightNode->lazy += currNode->lazy;
        }

        currNode->lazy = 0;
    }

    if(le >= left && ri <= right)
    {
        currNode->val += (ri - le + 1) * newVal;

        if(le != ri)
        {
            currNode->leftNode->lazy += newVal;
            currNode->rightNode->lazy += newVal;
        }

        return;
    }

    long long riLeft = currNode->rightNode->le, riRight = currNode->rightNode->ri, leLeft = currNode->leftNode->le, leRight = currNode->leftNode->ri;
    if(riLeft <= right && riRight >= left) updateRange(currNode->rightNode, left, right, newVal);
    if(leLeft <= right && leRight >= left) updateRange(currNode->leftNode, left, right, newVal);

    if(currNode->leftNode->lazy != 0)
    {
        currNode->leftNode->val += (currNode->leftNode->ri - currNode->leftNode->le + 1) * currNode->leftNode->lazy;

        if(currNode->leftNode->le != currNode->leftNode->ri)
        {
            currNode->leftNode->leftNode->lazy += currNode->leftNode->lazy;
            currNode->leftNode->rightNode->lazy += currNode->leftNode->lazy;
        }

        currNode->leftNode->lazy = 0;
    }
    if(currNode->rightNode->lazy != 0)
    {
        currNode->rightNode->val += (currNode->rightNode->ri - currNode->rightNode->le + 1) * currNode->rightNode->lazy;

        if(currNode->rightNode->le != currNode->rightNode->ri)
        {
            currNode->rightNode->leftNode->lazy += currNode->rightNode->lazy;
            currNode->rightNode->rightNode->lazy += currNode->rightNode->lazy;
        }

        currNode->rightNode->lazy = 0;
    }

    currNode->val = currNode->leftNode->val + currNode->rightNode->val;
}
long long queryRange(node *currNode, long long left, long long right)
{
    long long le = currNode->le, ri = currNode->ri;

    if(currNode->lazy != 0)
    {
        currNode->val += (ri - le + 1) * currNode->lazy;

        if(le != ri)
        {
            currNode->leftNode->lazy += currNode->lazy;
            currNode->rightNode->lazy += currNode->lazy;
        }

        currNode->lazy = 0;
    }

    if(le >= left && ri <= right) return currNode->val;

    long long riLeft = currNode->rightNode->le, riRight = currNode->rightNode->ri, leLeft = currNode->leftNode->le, leRight = currNode->leftNode->ri, ans = 0;
    if(riLeft <= right && riRight >= left) ans += queryRange(currNode->rightNode, left, right);
    if(leLeft <= right && leRight >= left) ans += queryRange(currNode->leftNode, left, right);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>n>>q;
        buildTree(root, 0, n - 1);

        for(int i = 0; i < q; i++)
        {
            cin>>type>>x>>y;

            if(type == 0)
            {
                cin>>v;
                updateRange(root, x - 1, y - 1, v);
            }
            else cout<<queryRange(root, x - 1, y - 1)<<endl;
        }
    }

    return 0;
}
