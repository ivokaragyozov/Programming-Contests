#include<iostream>
#include<vector>
#include<queue>
#define endl '\n'
using namespace std;

struct node
{
    int brg;
    vector<int> v;

    void add(int a)
    {
        v.push_back(a);
    }
};

int n, a, b, c, be, dep, tdep, tmp, ans;
bool used[205];
node nodes[205];
queue<int> q;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        nodes[i+1].brg=a;
        for(int i=0; i<b; i++)
        {
            cin>>c;
            nodes[i+1].add(c);
        }
    }
    cin>>be>>dep;
}
void bfs()
{
    q.push(be);
    used[be]=1;
    while(!q.empty())
    {
        if(tdep==dep)break;
        tmp=q.front();
        cout<<tmp<<endl;
        q.pop();
        for(int i=0; i<nodes[tmp].v.size(); i++)
        {
            if(!used[nodes[tmp].v[i]])
            {
                q.push(nodes[tmp].v[i]);
                ans+=nodes[tmp].brg;
            }
        }
        tdep++;
    }
}


int main()
{
    input();
    bfs();
    cout<<ans<<endl;
}
