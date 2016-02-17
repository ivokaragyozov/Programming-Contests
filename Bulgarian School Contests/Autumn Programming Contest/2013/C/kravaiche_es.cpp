/**
Ivo Karagyozov
Esenen 2013 C1 kravaiche
*/
#include<iostream>
using namespace std;
const int N=1000005;
int gHouseCount,gKoledariCount;
int gKravai,gOstatuci[N],gSum;
int main()
{
    cin>>gKoledariCount>>gHouseCount;
    for(int i=0;i<gHouseCount;i++)
    {
        gOstatuci[i]=-1;

    }

    for(int i=0;i<gHouseCount;i++)
    {
        cin>>gKravai;
        gSum=(gSum+gKravai)%gKoledariCount;
        if(gKravai%gKoledariCount==0)
        {
            cout<<i+1<<endl;
            return 0;
        }
        if(gOstatuci[gSum]==-1 && gSum!=0)
        {
            gOstatuci[gSum]=i+1;
        }
        else
        {
            for(int j=gOstatuci[gSum]+1;j<i;j++)
            {
                cout<<j+1<<" ";
            }
            cout<<i+1<<endl;
            return 0;
        }
    }

    return 0;

}
