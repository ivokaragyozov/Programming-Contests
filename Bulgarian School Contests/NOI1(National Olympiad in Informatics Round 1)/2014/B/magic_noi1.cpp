/**
Ivo Karagyozov
NOI1 2014 B3 magic
*/
#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

short a[9];
int tsum=0, ans=0;
bool p=0;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<9; i++)
    {
        cin>>a[i];
    }
}
void output()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<ans<<endl;
}
int sum(int number)
{
    if(number==1)
    {
        return a[0]+a[1]+a[2];
    }
    else if(number==2)
    {
        return a[3]+a[4]+a[5];
    }
    else if(number==3)
    {
        return a[6]+a[7]+a[8];
    }
    else if(number==4)
    {
        return a[0]+a[3]+a[6];
    }
    else if(number==5)
    {
        return a[1]+a[4]+a[7];
    }
    else if(number==6)
    {
        return a[2]+a[5]+a[8];
    }
    else if(number==7)
    {
        return a[0]+a[4]+a[8];
    }
    else
    {
        return a[2]+a[4]+a[6];
    }
}

int main()
{
    input();
    sort(a, a+9);
    do
    {
        tsum=sum(1);
        p=true;
        for(int i=2; i<=8; i++)
        {
            if(sum(i)!=tsum)
            {
                p=false;
                break;
            }
        }
        if(p)ans++;
    }
    while(next_permutation(a, a+9));
    output();
    return 0;
}
