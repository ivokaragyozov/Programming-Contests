#include<iostream>
using namespace std;

string s, t="CODEFORCES";
int brlb, brle, indt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!=t[i])break;
        else brlb++;
    }
    indt=t.size()-1;
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i]!=t[indt])break;
        else
        {
            brle++;
            indt--;
        }
    }
    if(brlb+brle>=t.size())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
