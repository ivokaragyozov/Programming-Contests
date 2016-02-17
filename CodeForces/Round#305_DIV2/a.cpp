#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

string s, t;
int k, len, ind=0;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s>>k;
}
bool isPal(string p)
{
    string q = p;
    reverse(p.begin(), p.end());
    return (q==p);
}

int main()
{
    input();
    if(s.size()%k!=0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    len=s.size()/k;
    for(int i=0; i<k; i++)
    {
        t=s.substr(ind, len);
        ind+=len;
        if(!isPal(t))
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
