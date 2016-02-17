#include<iostream>
using namespace std;
long long pows[12]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048}, exits[2050];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, a[2050];
    cin>>n;
    for(int i=2; i<pows[n+1]; i++)
    {
        cin>>a[i];
    }
    long long maxsum=0;
    for(int i=pows[n]; i<=pows[n+1]-1; i++)
    {
        int j=i;
        while(j>1)
        {
            exits[i]+=a[j];
            j/=2;
        }
        if(exits[i]>maxsum)maxsum=exits[i];
    }
    long long sum=0;
    for(int i=pows[n]; i<=pows[n+1]/2; i++)
    {
        if(exits[i/2]>=maxsum-exits[i])continue;
        sum+=maxsum-exits[i/2]-exits[i];
        exits[2]+=maxsum-exits[i/2]-exits[i];
        int bronrow=2;
        for(int j=3; j<=pows[n-1]; j++)
        {
            for(int k=0; k<bronrow; k++)
            {
                exits[pows[j-1]+k]=exits[2];
            }
            bronrow++;
        }
    }
    for(int i=pows[n+1]/2+1; i<=pows[n+1]-1; i++)
    {
        if(exits[i/2]>=maxsum-exits[i])continue;
        sum+=maxsum-exits[i/2]-exits[i];
        exits[3]+=maxsum-exits[i/2]-exits[i];
        int bronrow=2;
        for(int j=3; j<=pows[n-1]; j++)
        {
            for(int k=0; k<bronrow; k++)
            {
                exits[pows[j]-1-k]=exits[2];
            }
            bronrow++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
