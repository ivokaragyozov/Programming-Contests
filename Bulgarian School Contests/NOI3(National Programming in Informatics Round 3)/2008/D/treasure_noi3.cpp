/**
Ivo Karagyozov
NOI3 2008 D2 treasure
*/
#include<iostream>
using namespace std;
int brl[55];
int main()
{
    int n;
    cin>>n;
    string s,t;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<55;j++)
        {
            brl[j]=0;
        }
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]>='A' && s[j]<='Z')
            {
                brl[s[j]-'A']++;
            }
            else
            {
                brl[s[j]-'a'+26]++;
            }
        }
        int j=0;
        while(brl[j]==0)
        {
            j++;
        }
        j++;
        bool p=false;
        while(brl[j]!=0)
        {
            j++;
            if(j==52)
            {
                p=true;
                break;
            }
        }
        if(p==true)t=t+'.';
        else
        {
            if(j>=26)
            {
                t=t+((char)((j-26)+'a'));
            }
            else t=t+((char)(j+'A'));
        }
    }
    cout<<t<<endl;
    return 0;
}
