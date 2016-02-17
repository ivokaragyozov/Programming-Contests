#include<iostream>
#define endl '\n'
using namespace std;

int n;
long long maxt, p, t;
string s, ans;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        t=0;
        p=1;
        for(int j=0; j<s.size(); j++)
        {
            char let=tolower(s[j]);
            t+=(let-'a'+1)*p;
            p*=2;
        }
        if(t>maxt)
        {
            maxt=t;
            ans=s;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    cout<<ans<<endl;
    return 0;
}
