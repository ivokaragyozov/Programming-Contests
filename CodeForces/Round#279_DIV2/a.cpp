/**
100 points
Ivo Karagyozov
*/
#include<iostream>
using namespace std;
int math[5000], programming[5000], PE[5000], indM, indP, indPE, n;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            programming[indP]=i;
            indP++;
        }
        else if(a==2)
        {
            math[indM]=i;
            indM++;
        }
        else
        {
            PE[indPE]=i;
            indPE++;
        }
    }
    int minTeams=min(min(indP, indM),indPE);
    cout<<minTeams<<endl;
    for(int i=0; i<minTeams; i++)
    {
        cout<<programming[i]<<" "<<math[i]<<" "<<PE[i]<<endl;
    }
    return 0;
}
