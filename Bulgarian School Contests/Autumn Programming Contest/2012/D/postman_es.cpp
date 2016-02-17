/**
Ivo Karagyozov
Esenen 2012 D2 postman
*/
#include<iostream>
using namespace std;
int n, k, d[100010];
int main()
{
    cin>>n>>k;
    for(int i=1; i<n; i++)
    {
        cin>>d[i];
    }
    int Le=k, Ri=k, distp=0, dist_Le_Ri=0, lastpos=k;
    while(true)
    {
        if(lastpos==1 && Ri!=n)
        {
            lastpos=Ri+1;
            dist_Le_Ri+=d[Ri];
            distp+=dist_Le_Ri;
            Ri++;
        }
        else if(lastpos==1 && Ri==n)break;
        else if(lastpos==n && Le!=1)
        {
            lastpos=Le-1;
            dist_Le_Ri+=d[Le-1];
            distp+=dist_Le_Ri;
            Le--;
        }
        else if(lastpos==n && Le==1)break;
        else
        {
            if(lastpos==Le)
            {
                int dist1=d[Le-1], dist2=dist_Le_Ri+d[Ri];
                if(dist1<=dist2)
                {
                    lastpos=Le-1;
                    dist_Le_Ri+=d[Le-1];
                    distp+=d[Le-1];
                    Le--;
                }
                else
                {
                    lastpos=Ri+1;
                    dist_Le_Ri+=d[Ri];
                    distp+=dist_Le_Ri;
                    Ri++;
                }
            }
            else
            {
                int dist1=dist_Le_Ri+d[Le-1], dist2=d[Ri];
                if(dist1<=dist2)
                {
                    lastpos=Le-1;
                    dist_Le_Ri+=d[Le-1];
                    distp+=dist_Le_Ri;
                    Le--;
                }
                else
                {
                    lastpos=Ri+1;
                    dist_Le_Ri+=d[Ri];
                    distp+=d[Ri];
                    Ri++;
                }
            }
        }
    }
    cout<<distp<<endl;
    return 0;
}
