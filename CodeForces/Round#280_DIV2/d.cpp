#include<iostream>
using namespace std;
int main()
{
    int n, x, y, brTimesX=0, brTimesY=0;
    cin>>n>>x>>y;
    double timeX=0, timeY=0, nextHitX=1.0/x, nextHitY=1.0/y;
    for(int i=0; i<n; i++)
    {
        int live;
        cin>>live;
        timeX=0;
        timeY=0;
        nextHitX=1.0/x;
        nextHitY=1.0/y;
        while(live>0)
        {
            if(nextHitX<nextHitY)
            {
                timeX=nextHitX;
                nextHitX+=1.0/x;
            }
            else if(nextHitX>nextHitY)
            {
                timeY=nextHitY;
                nextHitY+=1.0/y;
            }
            else
            {
                timeX=nextHitX;
                nextHitX+=1.0/x;
                timeY=nextHitY;
                nextHitY+=1.0/y;
            }
            cout<<timeX<<" "<<nextHitX<<" "<<timeY<<" "<<nextHitY<<endl;
            live--;
        }
        if(timeX>timeY)cout<<"Vanya"<<endl;
        else if(timeX<timeY)cout<<"Vova"<<endl;
        else cout<<"Both"<<endl;
    }
    return 0;
}
