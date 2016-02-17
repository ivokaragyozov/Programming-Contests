#include<iostream>
#include<algorithm>
using namespace std;
bool ispal(string n)
{
    string m=n;
    reverse(m.begin(),m.end());
    if(m==n)return true;
    return false;
}
int main()
{
    long long n,br=0,a[40];
    string s;
    cin>>n;
    for(int i=2;i<=36;i++)
    {
        s="";
        int m=n;
        while(m>0)
        {
            char c;
            int ost=m%i;
            if(ost>=10)
            {
                ost=ost-10;
                c=(char)(ost+'a');
            }
            else
            {
                c=(char)(ost+'0');
            }
            s=c+s;
            m=m/i;
        }
        if(ispal(s)==true)
        {
            a[br]=i;
            br++;
        }
    }
    sort(a,a+br);
    if(br==0)
    {
        cout<<"none"<<endl;
        return 0;
    }
    else if(br==1)cout<<"unique"<<endl;
    else cout<<"multiple"<<endl;
    for(int i=0;i<br-1;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[br-1]<<endl;
    return 0;
}
