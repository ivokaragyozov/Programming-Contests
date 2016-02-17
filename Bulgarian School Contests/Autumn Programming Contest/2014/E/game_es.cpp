/**
Ivo Karagyozov
Esenen 2014 E1 game
*/
#include<iostream>
using namespace std;
bool n[4];
int main()
{
    int num[4], ans[4]= {0, 0, 0, 0}, ind=0, pos=0;
    cin>>num[0]>>num[1]>>num[2]>>num[3];
    for(int i=0; i<4; i++)
    {
        if(num[i]!=0)n[num[i]-1]=true;
    }
    for(int i=0; i<4; i++)
    {
        if(num[i]==0)
        {
            for(int j=0; j<4; j++)
            {
                if(n[j]==false)
                {
                    pos=i+1;
                    ans[ind]=j+1;
                    ind++;
                    n[j]=true;
                    break;
                }
            }
        }
    }
    if(ind==0)
    {
        cout<<num[0]<<" "<<num[1]<<endl;
        return 0;
    }
    if(ind==1)
    {
        cout<<pos<<" "<<ans[0]<<endl;
        return 0;
    }
    for(int i=0; i<ind-1; i++)cout<<ans[i]<<" ";
    cout<<ans[ind-1]<<endl;
    return 0;
}
