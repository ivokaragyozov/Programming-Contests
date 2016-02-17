/**
Ivo Karagyozov
Esenen 2014 D1 equality
*/
#include<iostream>
#include<string>
using namespace std;
char ch[36]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
long long quickStep(long long num, int step)
{
    if(step==1)return num;
    else if(step%2==0)return quickStep(num, step/2)*quickStep(num, step/2);
    else return quickStep(num, step-1)*num;
}
bool isCan(string num, int p)
{
    char maxChar=ch[p-1];
    for(int i=0; i<num.size(); i++)
    {
        if(num[i]>maxChar)return false;
    }
    return true;
}
long long fromPto10(string num, int p)
{
    if(isCan(num, p)==false)return -1;
    long long ind=1, step=0;
    long long sum=0;
    for(int i=num.size()-1; i>=0; i--)
    {
        if(num[i]>='0' && num[i]<='9')
        {
            int dig=num[i]-'0';
            sum=sum+ind*dig;
        }
        else
        {
            int dig=num[i]-'A'+10;
            sum=sum+ind*dig;
        }
        step++;
        ind=quickStep(p, step);
    }
    return sum;
}
int main()
{
    string s1, s2, s3;
    char a;
    int b=1;
    getline(cin, s1, '+');
    getline(cin, s2, '=');
    getline(cin, s3);
    for(int i=2; i<=36; i++)
    {
        long long x=fromPto10(s1, i);
        long long y=fromPto10(s2, i);
        long long z=fromPto10(s3, i);
        if(x!=-1 && y!=-1 && z!=-1 && x+y==z)
        {
            cout<<i<<endl;
            return 0;
        }
    }
}
