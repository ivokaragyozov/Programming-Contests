/**
Ivo Karagyozov
Esenen 2013 D2 salary
*/
#include<iostream>
using namespace std;
string toString(long long num)
{
    string ans="";
    while(num>0)
    {
        ans+=(char)(num%10+'0');
        num/=10;
    }
    return ans;
}
int main()
{
    long long k;
    cin>>k;
    string s;
    long long brdigs=0;
    char dig;
    for(long long i=1; ; i++)
    {
        unsigned long long num = i * i * i;
        string m=toString(num);
        bool p=false;
        for(int j=m.size()-1;j>=0;j--)
        {
            brdigs++;
            if(brdigs==k)
            {
                dig=m[j];
                p=true;
                break;
            }
        }
        if(p==true)break;
    }
    cout<<dig<<endl;
    return 0;
}
