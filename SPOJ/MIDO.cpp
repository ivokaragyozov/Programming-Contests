#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxSeconds = 48 * 60;

char buf;
int n, team, minute, second, firstTeam, secondTeam, firstTime, secondTime;
vector<int> seconds[maxSeconds];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>team>>minute>>buf>>second;

        seconds[minute * 60 + second].push_back(team);
    }

    for(int i = 0; i < maxSeconds; i++)
    {
        for(int j = 0; j < seconds[i].size(); j++)
        {
            if(seconds[i][j] == 1) firstTeam++;
            else secondTeam++;
            //cout<<i<<" "<<seconds[i][j]<<" "<<secondTeam<<" "<<firstTeam<<endl;
        }

        if(firstTeam > secondTeam) firstTime++;
        else if(firstTeam < secondTeam) secondTime++;
    }

    if(firstTime / 60 < 10) cout<<0;
    cout<<firstTime / 60<<":";
    if(firstTime % 60 >= 10) cout<<firstTime % 60<<endl;
    else cout<<0<<firstTime % 60<<endl;
    if(secondTime / 60 < 10) cout<<0;
    cout<<secondTime / 60<<":";
    if(secondTime % 60 > 10) cout<<secondTime % 60<<endl;
    else cout<<0<<secondTime % 60<<endl;
    return 0;
}
