#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

struct action
{
    int time;
    char type;

    action(){}
    action(int time, char type)
    {
        this->time = time;
        this->type = type;
    }
};

int t, n, e, l, actionInd, curNumber, maxNumber;
action dp[210];

void init()
{
    actionInd = 0;
    curNumber = 0;
    maxNumber = 0;
}
bool cmp(action a, action b)
{
    if(a.time != b.time) return a.time < b.time;
    else return a.type < b.type;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>n;

        init();

        for(int i = 0; i < n; i++)
        {
            cin>>e>>l;
            dp[actionInd++] = action(e, 'e');
            dp[actionInd++] = action(l, 'l');
        }

        sort(dp, dp+actionInd, cmp);
        for(int i = 0; i < actionInd; i++)
        {
            if(dp[i].type == 'e') curNumber++;
            else curNumber--;

            if(curNumber > maxNumber) maxNumber = curNumber;
        }

        cout<<maxNumber<<endl;
    }

    return 0;
}
