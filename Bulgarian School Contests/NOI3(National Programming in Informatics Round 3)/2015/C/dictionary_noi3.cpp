#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define endl '\n'
using namespace std;

const int maxLen = 106, maxN = 2006;

struct str
{
    int node, lastNode;

    str(){}
    str(int node, int lastNode)
    {
        this->node = node;
        this->lastNode = lastNode;
    }
};

bool isFound, vis[maxLen];
int n, lenS, lenT, parent[maxLen], currInd;
string s, t, ans[maxN];
vector<int> v[maxLen];
queue<str> q;

void bfs()
{
    int currNode, lastNode = lenS;
    q.push(str(lenS, lenS + 1));

    while(!q.empty())
    {
        currNode = q.front().node;
        lastNode = q.front().lastNode;
        q.pop();

        if(vis[currNode]) continue;
        cout<<lastNode<<" "<<currNode<<endl;
        vis[currNode] = true;
        parent[lastNode] = currNode;

        for(int i = 0; i < v[currNode].size(); i++)
        {
            if(!vis[v[currNode][i]])
            {
                lastNode = currNode;
                q.push(str(v[currNode][i], currNode));
            }
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin>>s>>n;
    lenS = s.size();
    for(int i = 0; i < n; i++)
    {
        cin>>t;

        lenT = t.size();
        for(int j = 0; j <= lenS - lenT; j++)
        {
            isFound = true;
            for(int k = 0; k < lenT; k++)
            {
                if(s[j + k] != t[k])
                {
                    isFound = false;
                    break;
                }
            }

            if(isFound) v[j + lenT].push_back(j);
            //if(isFound) cout<<j + lenT<<" "<<j<<endl;
        }
    }

    memset(parent, -1, sizeof(parent));
    bfs();

    for(int i = 0; i <= lenS; i++) cout<<parent[i]<<" ";
    cout<<endl;

    for(int i = lenS; i > 0; )
    {
        for(int j = parent[i]; j <= i - 1; j++)
        {
            ans[currInd] += s[j];
        }
        currInd++;
        i = parent[i];
    }

    cout<<currInd<<endl;
    for(int i = currInd - 1; i >= 0; i--)
    {
        cout<<ans[i];
        if(i == 0) cout<<endl;
        else cout<<" ";
    }

    return 0;
}
