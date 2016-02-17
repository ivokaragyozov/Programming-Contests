#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e4 + 5, maxA = 1e6 + 5;

struct node
{
    int val, le, ri, lazy;
    node *leftNode, *rightNode;

    node()
    {
        val = 0;
        leftNode = NULL;
        rightNode = NULL;
        lazy = -1;
    }
};

int t, n, q, a[maxN], type, x, y, v, primes[maxA];
node *root = new node();

bool isPrime(int p)
{
    if(primes[p] != -1) return primes[p];
    if(p < 2) return false;
    if(p == 2) return true;
    if(p % 2 == 0) return false;

    for(int i = 3; i <= sqrt(p); i += 2)
    {
        if(p % i == 0)
        {
            primes[p] = false;
            return false;
        }
    }

    primes[p] = true;
    return true;
}
void buildTree(node *currNode, int le, int ri)
{
    currNode->le = le;
    currNode->ri = ri;

    if(le == ri)
    {
        if(isPrime(a[le])) currNode->val = 1;
        return;
    }

    currNode->leftNode = new node();
    currNode->rightNode = new node();

    int mid = (le + ri) / 2;
    buildTree(currNode->leftNode, le, mid);
    buildTree(currNode->rightNode, mid + 1, ri);
    currNode->val = currNode->leftNode->val + currNode->rightNode->val;

    //cout<<le<<" "<<ri<<" "<<currNode->val<<endl;
}
void updateRange(node *currNode, int left, int right, int newVal)
{
    int le = currNode->le, ri = currNode->ri;

    //cout<<le<<" "<<ri<<" "<<currNode->val<<endl;

    if(currNode->lazy != -1)
    {
        currNode->val = currNode->lazy * (ri - le + 1);

        if(le != ri)
        {
            currNode->leftNode->lazy = currNode->lazy;
            currNode->rightNode->lazy = currNode->lazy;
        }

        currNode->lazy = -1;
    }

    if(le >= left && ri <= right)
    {
        if(isPrime(newVal))
        {
            currNode->val = ri - le + 1;

            if(le != ri)
            {
                currNode->leftNode->lazy = 1;
                currNode->rightNode->lazy = 1;
            }
        }
        else
        {
            currNode->val = 0;

            if(le != ri)
            {
                currNode->leftNode->lazy = 0;
                currNode->rightNode->lazy = 0;
            }
        }

        //cout<<"updated "<<le<<" "<<ri<<" "<<currNode->val<<endl;

        return;
    }

    int riLeft = currNode->rightNode->le, riRight = currNode->rightNode->ri, leRight = currNode->leftNode->ri, leLeft = currNode->leftNode->le;
    if(riRight >= left && riLeft <= right) updateRange(currNode->rightNode, left, right, newVal);
    if(leRight >= left && leLeft <= right) updateRange(currNode->leftNode, left, right, newVal);

    if(currNode->leftNode->lazy != -1)
    {
        currNode->leftNode->val = (currNode->leftNode->ri - currNode->leftNode->le + 1) * currNode->leftNode->lazy;

        if(currNode->leftNode->le != currNode->leftNode->ri)
        {
            currNode->leftNode->leftNode->lazy = currNode->leftNode->lazy;
            currNode->leftNode->rightNode->lazy = currNode->leftNode->lazy;
        }

        currNode->leftNode->lazy = -1;
    }
    if(currNode->rightNode->lazy != -1)
    {
        currNode->rightNode->val = (currNode->rightNode->ri - currNode->rightNode->le + 1) * currNode->rightNode->lazy;

        if(currNode->rightNode->le != currNode->rightNode->ri)
        {
            currNode->rightNode->leftNode->lazy = currNode->rightNode->lazy;
            currNode->rightNode->rightNode->lazy = currNode->rightNode->lazy;
        }

        currNode->rightNode->lazy = -1;
    }
    currNode->val = currNode->leftNode->val + currNode->rightNode->val;
}
int queryRange(node *currNode, int left, int right)
{
    int le = currNode->le, ri = currNode->ri;
    //cout<<le<<" "<<ri<<endl;

    if(currNode->lazy != -1)
    {
        currNode->val = (ri - le + 1) * currNode->lazy;

        if(le != ri)
        {
            currNode->leftNode->lazy = currNode->lazy;
            currNode->rightNode->lazy = currNode->lazy;
        }

        currNode->lazy = -1;
    }

    if(le >= left && ri <= right) return currNode->val;

    int riLeft = currNode->rightNode->le, riRight = currNode->rightNode->ri, leRight = currNode->leftNode->ri, leLeft = currNode->leftNode->le, ans = 0;

    //cout<<"ri le "<<riLeft<<" "<<leRight<<endl;

    if(riRight >= left && riLeft <= right) ans += queryRange(currNode->rightNode, left, right);
    if(leRight >= left && leLeft <= right) ans += queryRange(currNode->leftNode, left, right);

    return ans;
}
void printTree(node* currNode)
{
    if(currNode == root) cout<<"-------------------------------------------------"<<endl;

    cout<<currNode->val<<" ";
    if(currNode->leftNode != NULL) printTree(currNode->leftNode);
    if(currNode->rightNode != NULL) printTree(currNode->rightNode);

    if(currNode == root) cout<<endl<<"-------------------------------------------------"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(primes, -1, sizeof(primes));

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cout<<"Case "<<cs + 1<<":"<<endl;
        cin>>n>>q;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        buildTree(root, 0, n - 1);
        //printTree(root);

        for(int i = 0; i < q; i++)
        {
            cin>>type>>x>>y;

            if(type == 0)
            {
                cin>>v;

                updateRange(root, x - 1, y - 1, v);
            }
            else cout<<queryRange(root, x - 1, y - 1)<<endl;

            //printTree(root);
        }
    }

    return 0;
}
