#include<iostream>
using namespace std;
int main()
{
    int n, sum=0, lastsum=0, i=0;
    cin>>n;
    for(i=1; ; i++)
    {
        lastsum+=i;
        sum+=lastsum;
        if(sum>n)break;
    }
    cout<<i-1<<endl;
    return 0;
}
