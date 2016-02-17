/**
Ivo Karagyozov
Proleten 2013 D2 travel
*/
#include<iostream>
using namespace std;
const int N=100005;
int cards[N][2];
int main()
{
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<=n;i++)
    {
        cards[i][0]=cards[i][1]=-1;
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        if(cards[a][0]==-1)cards[a][0]=b;
        else if(cards[a][1]==-1)cards[a][1]=b;
        if(cards[b][0]==-1)cards[b][0]=a;
        else if(cards[b][1]==-1)cards[b][1]=a;
    }
    int c=-1,d=-1;
    for(int i=0;i<n;i++)
    {
        if(cards[i][1]==-1 && i!=0)
        {
            if(c==-1)c=i;
            else
            {
                d=i;
                break;
            }
        }
        else if(cards[i][0]==-1)
        {
            if(i==0)c=i;
            else
            {
                d=i;
                break;
            }
        }
    }
    if(cards[c][0]==-1)cards[c][0]=d;
    else cards[c][1]=d;
    if(cards[d][0]==-1)cards[d][0]=c;
    else cards[d][1]=c;
    int road[N];
    road[0]=0;
    road[n]=n;
    cout<<"0 ";
    for(int i=1;i<n;i++)
    {
        if(i==1)
        {
            road[i]=cards[0][0];
        }
        else
        {
            int p=road[i-2];
            if(cards[road[i-1]][0]==p)road[i]=cards[road[i-1]][1];
            else road[i]=cards[road[i-1]][0];
        }
        cout<<road[i]<<" ";
    }
    cout<<n<<endl;
    return 0;
}
