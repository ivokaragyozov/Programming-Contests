#include<iostream>
using namespace std;
int main()
{
    int room,cond;
    cin>>room>>cond;
    char func;
    cin>>func;
    if(func=='v')cout<<room;
    else if(func=='a')cout<<cond;
    else if(func=='h')
    {
        if(cond<room)cout<<room;
        else cout<<cond;
    }
    else
    {
        if(cond>room)cout<<room;
        else cout<<cond;
    }
    cout<<endl;
    return 0;
}
