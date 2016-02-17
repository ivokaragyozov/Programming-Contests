#include<iostream>
using namespace std;

int k;
string n;

int brdigs(int n)
{
    int br=0;
    while(n>0)
    {
        br++;
        n/=10;
    }
    return br;
}
int strtoint(string s)
{
    int ans=0;
    for(int i=0; i<s.size(); i++)
    {
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}
string inttostr(int number)
{
    string s="";
    while(number>0)
    {
        s=(char)(number%10+'0')+s;
        number/=10;
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n.size(); i++)
    {
        if(n[i]-'0'>k)k=n[i]-'0';
    }
    cout<<k<<endl;
    for(int i=0; i<k; i++)
    {
        int ans=0;
        bool p=false;
        for(int j=0; j<n.size(); j++)
        {
            if(n[j]!='0')
            {
                p=true;
                ans=ans*10+1;
                n[j]=(char)(n[j]-'0'-1+'0');
            }
            else if(p)
            {
                ans*=10;
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}
