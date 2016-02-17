#include<iostream>
using namespace std;

long long n, k, maxp[1000005], p[1000005], days[1000005], sum=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>maxp[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
        for(int j=0; j<maxp[i]-p[i]; j++)
        {
            days[j]++;
        }
        sum+=p[i];
    }
    long long i=0;
    while(sum<k)
    {
        sum+=days[i];
        i++;
    }
    cout<<i<<endl;
    return 0;
}
