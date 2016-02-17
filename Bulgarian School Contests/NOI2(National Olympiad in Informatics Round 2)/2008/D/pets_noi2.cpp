/**
Ivo Karagyozov
NOI2 2008 D2 pets
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        int cat=0,gpi=0;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='C' || s[j]=='A' || s[j]=='T')cat++;
            else if(s[j]=='G' || s[j]=='P' || s[j]=='I')gpi++;
        }
        if(cat>gpi)cout<<"CAT";
        else if(cat<gpi)cout<<"GPI";
        else if(cat==gpi && cat!=0)cout<<"CAT-GPI";
        else cout<<"UFO";
        cout<<endl;
    }
    return 0;
}
