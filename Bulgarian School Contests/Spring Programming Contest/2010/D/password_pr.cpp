#include<iostream>
using namespace std;
string rot(string s,int p)
{
    swap(s[p],s[p+2]);
    swap(s[p+1],s[p+2]);
    return s;
}
int main()
{
    string t[100005],s,st;
    int br=1,j=0;
    cin>>s;
    t[j]=s;
    j++;
    int len=s.size();
    while(1)
    {
        int broi;
        if(j!=1)broi=br;
        else broi=0;
        for(int i=1;i<j;i++)
        {
            for(int p=0;p<len-2;p++)
            {
                st=rot(t[i],p);
                bool f=true;
                for(int k=0;k<br;k++)
                {
                    if(st==t[k])
                    {
                        f=false;
                        break;
                    }
                }
                if(f==true)
                {
                    t[br]=st;
                    br++;
                }
            }
        }
        if(broi==br)break;
    }
    cout<<br<<endl;
    return 0;
}
