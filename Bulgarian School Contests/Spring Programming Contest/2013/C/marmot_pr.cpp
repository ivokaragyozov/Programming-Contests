/**
Ivo Karagyozov
Proleten 2013 C3 marmot
*/
#include<iostream>
#define endl '\n'
using namespace std;

int n, l, k, a[1005];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>l>>k;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
}

int main()
{
    input();
    int p=0;
    for(int i=0; i<n; i++)
    {
        p=p^((l-a[i])%(k+1));
    }
    if(!p)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
