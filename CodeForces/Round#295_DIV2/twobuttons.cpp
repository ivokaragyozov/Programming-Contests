#include<iostream>
using namespace std;
int dyn[10005];
int n, m;

void recurse(int i, int br)
{
    dyn[i]=br;
    if(2*i<=10000 && (dyn[2*i]>br+1 || dyn[2*i]==0))
    {
        recurse(2*i, br+1);
    }
    if(i-1>=0 && (dyn[i-1]>br+1 || dyn[i-1]==0))
    {
        recurse(i-1, br+1);
    }
}

int main()
{
    cin>>n>>m;
    if(n>m)
    {
        cout<<n-m<<endl;
        return 0;
    }
    recurse(n, 0);
    cout<<dyn[m]<<endl;
    return 0;
}
