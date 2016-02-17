/**
Ivo Karagyozov
Esenen 2011 D2 profit
*/
#include<iostream>
#include<algorithm>
using namespace std;
int monitors[1000], blocks[1000];
int main()
{
    int brMonitor, brBlock;
    cin>>brBlock>>brMonitor;
    for(int i=0; i<brBlock; i++)
    {
        cin>>blocks[i];
    }
    for(int i=0; i<brMonitor; i++)
    {
        cin>>monitors[i];
    }
    sort(blocks, blocks+brBlock);
    sort(monitors, monitors+brMonitor);
    int ind=min(brBlock, brMonitor);
    int indMonitor=brMonitor-ind, indBlock=brBlock-ind;
    long long sum=0;
    for(int i=0; i<ind; i++)
    {
        sum+=monitors[indMonitor]*blocks[indBlock];
        indMonitor++;
        indBlock++;
    }
    cout<<ind<<" "<<sum<<endl;
    return 0;
}
