/**
Ivo Karagyozov
Prolenten 2012 D3 robo
*/
#include<iostream>
using namespace std;
int pos=0;
void position(char a)
{
    if(a=='S')pos=1;
    else if(a=='I')pos=2;
    else if(a=='J')pos=3;
    else if(a=='Z')pos=4;
    else if(a=='D')pos++;
    else if(a=='L')pos--;
    else if(a=='K')pos+=2;
    if(pos==0)pos=pos+4;
    else if(pos>4)pos=pos%4;
}
int main()
{
    char c;
    cin>>c;
    string s;
    cin>>s;
    position(c);
    int i=1,j=1;
    for(int p=0;p<s.size();p++)
    {
        if(s[p]=='N')
        {
            if(pos==1)i++;
            else if(pos==2)j++;
            else if(pos==3)i--;
            else if(pos==4)j--;
        }
        else
        {
            position(s[p]);
        }
    }
    cout<<j<<" "<<i<<" ";
    if(pos==1)cout<<"S";
    else if(pos==2)cout<<"I";
    else if(pos==3)cout<<"J";
    else if(pos==4)cout<<"Z";
    cout<<endl;
    int road1=0,road2=0;
    if(c!='S')road1=1;
    road1=road1+(i-1);
    if(j!=1)road1++;
    road1=road1+(j-1);
    if(pos!=2 && j!=1)road1++;
    else if(j==1 && pos!=1)road1++;
    if(c!='I')road2=1;
    road2=road2+(j-1);
    if(i!=1)road2++;
    road2=road2+(i-1);
    if(pos!=1 && i!=1)road2++;
    else if(i==1 && pos!=2)road2++;
    cout<<min(road1,road2)<<endl;
    return 0;
}
