#include<iostream>
using namespace std;

int t, a, b, ans, dyn[5000005];

int brdels(int n)
{
    if(n==1)return 0;
    dyn[n]=dyn[n/brdels(n)]+1;
    return dyn[n];
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int i=0; i<t; i++)
    {
        ans=0;
        cin>>a>>b;
        for(int i=b+1; i<=a; i++)
        {
            if(dyn[i]==0)
            {
                dyn[i]=brdels(i);
            }
            ans+=dyn[i];
        }
        cout<<ans<<endl;
    }
}

int main()
{
    input();
    return 0;
}
