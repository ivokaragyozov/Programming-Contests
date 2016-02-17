/**
Ivo Karagyozov
NOI3 2015 C1 cham
*/
#include<iostream>
#define endl '\n'
using namespace std;

long long n, a[100005], brpos=0;
long long ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=n-1; i>=0; )
    {
        int tmp=a[i], br=0;
        while(a[i]==tmp && i>=0)
        {
            br++;
            i--;
        }
        if(br*(tmp-brpos)<=0)break;
        ans+=br*(tmp-brpos);
        brpos+=br;
    }
    cout<<ans<<endl;
    return 0;
}
