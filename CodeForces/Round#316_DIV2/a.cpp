#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int n, m, maxPerCity = -1, winner, cntCities[105], maxCntCities, answer = 1000000;
vector<int> firstStageWinners;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        maxPerCity = -1;
        for(int j = 0; j < n; j++)
        {
            int a;
            cin>>a;
            if(a > maxPerCity)
            {
                maxPerCity = a;
                winner = j;
            }
        }
        //cout<<winner<<endl;
        firstStageWinners.push_back(winner);
    }

    for(int i = 0; i < firstStageWinners.size(); i++)
    {
        cntCities[firstStageWinners[i]]++;
        if(cntCities[firstStageWinners[i]] > maxCntCities)
        {
            maxCntCities = cntCities[firstStageWinners[i]];
            answer = firstStageWinners[i];
        }
        else if(cntCities[firstStageWinners[i]] == maxCntCities && firstStageWinners[i] < answer)
        {
            answer = firstStageWinners[i];
        }
    }

    cout<<answer+1<<endl;
    return 0;
}
