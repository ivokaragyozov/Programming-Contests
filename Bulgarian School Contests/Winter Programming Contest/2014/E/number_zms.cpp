/**
Ivo Karagyozov
Zimni 2014 D3 number
*/
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int br=0;
    unsigned long long sum=0;
    for(int i=a;i<=b;i++)
    {
        int num1=0,num2=0;
        int num=i;
        num1=num%10+num/10%10*10+num/100%10*100;
        num=num/1000;
        num2=num%10+num/10%10*10+num/100%10*100;
        if(i%(num1+num2)==0 && num1>99 && num2>99)
        {
            br++;
            sum=(unsigned long long)(sum+i);
        }
    }
    cout<<br<<" "<<sum<<endl;
    return 0;
}
