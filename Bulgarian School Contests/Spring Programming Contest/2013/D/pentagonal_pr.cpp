/**
Ivo Karagyozov
Proleten 2013 D3 pentagonal
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long k;
    for(int i=0; i<n; i++)
    {
        cin>>k;
        long long num=k*k;
        if(k%2!=0)num=num+(k-1)*(k/2)+(k-1)/2;
        else num=num+(k-1)*(k/2);
        cout<<num<<endl;
    }
    return 0;
}
