///   100 points
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int homeTeam[100], awayTeam[100];
bool homeT[100], awayT[100];
struct answer
{
    char team[21];
    int number;
    int minute;
};
answer ans[200];
int ind=0;
int main()
{
    char home[21], away[21];
    scanf("%s", &home);
    scanf("%s", &away);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int minute, number;
        char team, card;
        scanf("%d %c %d %c", &minute, &team, &number, &card);
        if(team=='h')
        {
            if(card=='y')homeTeam[number]++;
            else homeTeam[number]+=2;
            if(homeTeam[number]>=2 && homeT[number]==false)
            {
                homeT[number]=true;
                ans[ind].minute=minute;
                ans[ind].number=number;
                strcpy(ans[ind].team, home);
                ind++;
            }
        }
        else
        {
            if(card=='y')awayTeam[number]++;
            else awayTeam[number]+=2;
            if(awayTeam[number]>=2 && awayT[number]==false)
            {
                awayT[number]=true;
                ans[ind].minute=minute;
                ans[ind].number=number;
                strcpy(ans[ind].team, away);
                ind++;
            }
        }
    }
    if(ind==0)return 0;
    for(int i=0; i<ind; i++)
    {
        printf("%s %d %d\n", ans[i].team, ans[i].number, ans[i].minute);
    }
    return 0;
}
