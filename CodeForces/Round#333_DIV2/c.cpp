#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 405;

bool towns[maxN];
int n, m, a, b, visTrain[maxN], visCar[maxN];
vector<int> graphTrain[maxN], graphCar[maxN];
queue<int> q;

void bfsTrain()
{
    int node;
    q.push(1);
    visTrain[1] = 1;

    while(!q.empty())
    {
        node = q.front();
        q.pop();

        for(int i = 0; i < graphTrain[node].size(); i++)
        {
            if(!visTrain[graphTrain[node][i]])
            {
                visTrain[graphTrain[node][i]] = visTrain[node] + 1;
                q.push(graphTrain[node][i]);
            }
        }
    }
}
void bfsCar()
{
    int node;
    q.push(1);
    visCar[1] = 1;

    while(!q.empty())
    {
        node = q.front();
        q.pop();

        for(int i = 0; i < graphCar[node].size(); i++)
        {
            if(!visCar[graphCar[node][i]])
            {
                visCar[graphCar[node][i]] = visCar[node] + 1;
                if(visCar[graphCar[node][i]] == visTrain[graphCar[node][i]] && graphCar[node][i] != n) visCar[graphCar[node][i]] += 2;
                q.push(graphCar[node][i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;

        graphTrain[a].push_back(b);
        graphTrain[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        memset(towns, 0, sizeof(towns));

        for(int j = 0; j < graphTrain[i].size(); j++)
        {
            towns[graphTrain[i][j]] = true;
        }

        for(int j = 1; j <= n; j++)
        {
            if(!towns[j]) graphCar[i].push_back(j);
            //if(!towns[j]) cout<<i<<" "<<j<<endl;
        }
    }

    bfsTrain();
    bfsCar();

    if(min(visCar[n], visTrain[n]) == 0)
    {
        cout<<-1<<endl;
        return 0;
    }

    cout<<max(visCar[n], visTrain[n]) - 1<<endl;
    return 0;
}

