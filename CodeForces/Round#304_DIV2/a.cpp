#include<iostream>
using namespace std;

long long k, n, w;
long long need=0;

void input()
{
    cin>>k>>n>>w;
}
void output()
{
    if(need>n)cout<<need-n<<endl;
    else cout<<0<<endl;
}

int main()
{
    input();
    for(int i=1; i<=w; i++)
    {
        need+=i*k;
    }
    output();
}
