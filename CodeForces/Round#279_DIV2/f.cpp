#include<iostream>
#include<vector>
using namespace std;
int n, br=0, brMax=0, lastVisited=0;
bool used[6005];
struct nodes
{
    int weight, br;
    vector<int> neigh;
};
nodes node[6005];
void dfs(int nod, int lastnod)
{
    used[nod]=true;
    if(node[nod].weight>lastVisited && node[nod].br<node[lastnod].br+1)
    {
        cout<<"ivo"<<endl;
        node[nod].br=node[lastnod].br+1;
    }
    else if(node[nod].weight<=lastVisited && node[nod].br<node[lastnod].br);
    {
        node[nod].br=node[lastnod].br;
    }
    if(node[nod].weight>lastVisited)lastVisited=node[nod].weight;

    for(int i=0; i<node[nod].neigh.size(); i++)
    {
        if(used[node[nod].neigh[i]]==false)
        {
            cout<<nod<<" "<<node[nod].br<<" "<<node[nod].weight<<" "<<lastVisited<<" "<<lastnod<<endl;
            lastnod=nod;
            dfs(node[nod].neigh[i], lastnod);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>node[i].weight;
    }
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        node[a-1].neigh.push_back(b-1);
        node[b-1].neigh.push_back(a-1);
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            node[j].br=1;
        }
        used[0]=true;
        dfs(i, i-1);
        for(int j=0; j<n; j++)
        {
            if(node[j].br>brMax)brMax=node[j].br;
        }
        break;
    }
    cout<<brMax<<endl;
    return 0;
}
