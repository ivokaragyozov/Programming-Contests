#include<iostream>
using namespace std;
int n, ans=0;
string s, t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n;
    cin>>s>>t;
    for(int i=0; i<n; i++)
    {
        int a=s[i]-'0', b=t[i]-'0';
        int p1, p2;
        if(a>b)
        {
            p1=a-b;
            p2=9-a+b+1;
        }
        else
        {
            p1=a+9-b+1;
            p2=b-a;
        }
        ans+=min(p1, p2);
    }
    cout<<ans<<endl;
    return 0;
}
