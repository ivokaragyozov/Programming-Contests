/**
Ivo Karagyozov
Esenen 2010 D3 planes
*/
#include<iostream>
using namespace std;
int n, d, ap1, ap2, posPl1=0, posPl2=0, brMeet=1, brRazm=0, distPl1=0, distPl2=0;
bool airportsPl1[1000], airportsPl2[1000];
bool isReady1()
{
    for(int i=0; i<n; i++)
    {
        if(airportsPl1[i]==false)return false;
    }
    return true;
}
bool isReady2()
{
    for(int i=0; i<n; i++)
    {
        if(airportsPl2[i]==false)return false;
    }
    return true;
}
int main()
{
    airportsPl1[0]=true;
    airportsPl2[0]=true;
    cin>>n>>d>>ap1>>ap2;
    while(isReady1()==false || isReady2()==false)
    {
        if(isReady1()==false)
        {
            for(int i=0; i<ap1+1; i++)
            {
                posPl1++;
                posPl1%=n;
                distPl1+=d;
                if(posPl1==posPl2)brRazm++;
            }
            while(airportsPl1[posPl1]==true)
            {
                posPl1++;
                posPl1%=n;
                distPl1+=d;
                if(posPl1==posPl2)brRazm++;
            }
            airportsPl1[posPl1]=true;
            if(posPl1==posPl2)
            {
                brMeet++;
                brRazm--;
            }
        }
        if(isReady2()==false)
        {
            for(int i=0; i<ap2+1; i++)
            {
                posPl2--;
                if(posPl2==-1)posPl2=n-1;
                distPl2+=d;
                if(posPl1==posPl2)brRazm++;
            }
            while(airportsPl2[posPl2]==true)
            {
                posPl2--;
                if(posPl2==-1)posPl2=n-1;
                distPl2+=d;
                if(posPl1==posPl2)brRazm++;
            }
            airportsPl2[posPl2]=true;
            if(posPl1==posPl2)
            {
                brMeet++;
                brRazm--;
            }
        }
    }
    cout<<distPl1<<" "<<distPl2<<" "<<brMeet<<" "<<brRazm<<endl;
    return 0;
}
