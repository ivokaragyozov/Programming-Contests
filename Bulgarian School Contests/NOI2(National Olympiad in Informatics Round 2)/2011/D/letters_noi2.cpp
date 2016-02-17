/**
Ivo Karagyozov
NOI2 2011 D1 letters
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char a;
    cin>>a;
    string s;
    char k;
    cin.get(k);
    int br1=0,br2=0,br3=0,br4=0;
    for(int j=0;j<n;j++)
    {
        cin>>s;
        if(tolower(s[0])==a)br1++;
        cin>>s;
        int br=0;
        for(int i=0;i<s.size();i++)
        {
            if(tolower(s[i])==a)br++;
        }
        if(br>0)br2++;
        cin>>s;
        br=0;
        for(int i=0;i<s.size();i++)
        {
            if(tolower(s[i])==a)br++;
        }
        if(br>1)br3++;
        cin>>s;
        if(tolower(s[s.size()-1])==a)br4++;
    }
    cout<<br1<<" "<<br2<<" "<<br3<<" "<<br4<<endl;
    return 0;
}
