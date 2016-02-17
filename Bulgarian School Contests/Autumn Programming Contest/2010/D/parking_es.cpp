/**
Ivo Karagyozov
Esenen 2010 D2 parking
*/
#include<iostream>
using namespace std;
int ans[25], ind=0;
int main()
{
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        int br=0;
        for(int j=0; j<s.size(); j++)
        {
            bool p1=false, p2=false, p3=false;
            if(s[j]=='-')
            {
                if((j<=s.size()-3 && s[j+2]=='B') || (j<=s.size()-2 && s[j+1]=='B'))p1=true;
                if(j>=1 && s[j-1]=='S')p2=true;
                if(j<=s.size()-2 && s[j+1]=='S')p3=true;
            }
            if(p1==false && p2==false && p3==false && s[j]=='-')
            {
                br++;
            }
        }
        ans[ind]=br;
        ind++;
    }
    for(int i=0; i<ind-1; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<ans[ind-1]<<endl;
    return 0;
}
