#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d[105], ind=0;
    cin>>n;
    string s;
    cin>>s;
    int firstI=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='*')
        {
            d[ind]=i+1;
        }
        else
        {
            d[ind]=0;
        }
        ind++;
    }
    for(int j=0; j<n; j++)
    {
        if(s[j]=='.')continue;
        firstI=j;
        for(int i=1; i<=n/5; i++)
        {
            if(d[firstI+i]!=0 && d[firstI+2*i]!=0 && d[firstI+3*i]!=0 && d[firstI+4*i]!=0 && 4*i<n)
            {
                cout<<"yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"no"<<endl;
    return 0;
}
