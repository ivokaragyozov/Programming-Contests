#include<iostream>
#include<vector>
using namespace std;
int dig[32];
int j=0;
vector<int> right1;
vector<int> left1;
void f10to3(int num)
{
    j=0;
    while(num>0)
    {
        dig[j] = num%3;
        num /= 3;
        j++;
    }
}
int main()
{
    char a;
    cin>>a;
    int b;
    cin>>b;
    f10to3(b);
    int pow1=1;
    for(int i=0;i<=j;i++)
    {
        if(dig[i]==1)
        {
            if(a=='L')right1.push_back(pow1);
            else left1.push_back(pow1);
        }
        else if(dig[i]==2)
        {
            if(a=='L')left1.push_back(pow1);
            else right1.push_back(pow1);
            dig[i+1]++;
        }
        pow1*=3;
    }
    cout<<"L:";
    for(int i=0;i<left1.size();i++)
    {
        cout<<left1[i]<<" ";
    }
    cout<<endl;
    cout<<"R:";
    for(int i=0;i<right1.size();i++)
    {
        cout<<right1[i]<<" ";
    }
    cout<<endl;
    return 0;
}
