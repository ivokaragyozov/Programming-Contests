/**
Ivo Karagyozov
NOI1 2014 C1 xsum
*/
#include<iostream>
using namespace std;
int array1[50001], array2[50001];
int main()
{
    int n, sum;
    cin>>n>>sum;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        if(a>=0)array1[a]++;
        else array2[-a]++;
    }
    long long br=0;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        int need = sum-a;
        if(need>=0)br+=(long long)array1[need];
        else br+=(long long)array2[-need];
    }
    cout<<br<<endl;
    return 0;
}
