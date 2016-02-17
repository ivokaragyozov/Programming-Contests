/**
Ivo Karagyozov
NOI1 2014 C2 runners
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct runner
{
    int timeStart;
    int timeEnd;
    int timeRun;
};
int cmp(runner s, runner t)
{
    if(s.timeRun!=t.timeRun)return s.timeRun<t.timeRun;
    else return s.timeStart<t.timeStart;
}
runner runners[105];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        runners[i].timeStart=i;
    }
    int x=5;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        runners[a].timeEnd=x;
        x++;
        runners[a].timeRun=runners[a].timeEnd-runners[a].timeStart;
    }
    sort(runners+1, runners+n+1, cmp);
    int lastnum=-1, brtimes=0, ind=0;
    for(int i=1; i<=n; i++)
    {
        if(runners[i].timeRun!=lastnum)
        {
            lastnum=runners[i].timeRun;
            brtimes++;
            if(brtimes==3)
            {
                ind=i;
                break;
            }
        }
    }
    if(ind==0 || ind==n+1)
    {
        cout<<0<<endl;
        return 0;
    }
    int ans[105]={runners[ind++].timeStart}, index=1;
    while(runners[ind-1].timeRun==runners[ind].timeRun && ind<=n)
    {
        ans[index++] = runners[ind++].timeStart;
    }
    cout<<index<<" ";
    for(int i=0; i<index-1; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<ans[index-1]<<endl;
    return 0;
}
