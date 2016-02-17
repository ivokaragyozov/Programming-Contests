/**
Ivo Karagyozov
Zimni 2014 E2 camera
*/
#include<iostream>
using namespace std;
int main()
{
    int h,m,h1,m1;
    string s;
    getline(cin,s,'#');
    h=(s[1]-'0')+(s[0]-'0')*10;
    m=(s[3]-'0')+(s[2]-'0')*10;
    h1=(s[5]-'0')+(s[4]-'0')*10;
    m1=(s[7]-'0')+(s[6]-'0')*10;
    int t1=60*h+m;
    int t2=60*h1+m1;
    if(t2<t1)
    {
        t2=t2+24*60;
    }
    int t=t2-t1;
    cout<<t/60<<" "<<t%60<<endl;
    int brl=0,brt=0;
    for(int i=8;i<s.size();)
    {
        while(isalpha(s[i]))
        {
            if(s[i]<='z' && s[i]>='a')
            {
                brt++;
                brl--;
            }
            else
            {
                brl++;
            }
            i++;
            if(i==s.size())break;
        }
        if(i==s.size())break;
        int num=0;
        int j=i;
        while(isdigit(s[i]))
        {
            num=10*num+(s[i]-'0');
            i++;
        }
        if(s[j-1]<='z' && s[j-1]>='a')
        {
            brt=brt+(num-1);
        }
        else brl=brl+(num-1);
    }
    cout<<brl<<" "<<brt<<endl;
    return 0;
}
