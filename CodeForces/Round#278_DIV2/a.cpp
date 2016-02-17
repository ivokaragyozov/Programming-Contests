/**
100 points
Ivo Karagyozov
*/
#include<iostream>
using namespace std;
bool isLucky(int floor)
{
    while(floor!=0)
    {
        if(floor%10==8 || floor%10==-8)return true;
        floor/=10;
    }
    return false;
}
int main()
{
    int floor;
    cin>>floor;
    int ans=1;
    floor++;
    while(isLucky(floor)==false)
    {
        floor++;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
