/**
Ivo Karagyozov
Esenen 2013 C3 next
*/
#include <iostream>

using namespace std;

const long long N=10000000000;
long long cntNums;
bool digs[10];

long long turn(long long num)
{
    long long num1=0;
    while(num>0)
    {
        num1=num1*10+num%10;
        num/=10;
    }

    return num1;
}

bool isAns(long long num)
{
    bool dig[10]= {0,0,0,0,0,0,0,0,0,0};

    while(num>0)
    {
        if(dig[num%10]==1)
        {
            return 0;
        }
        else
        {
            dig[num%10]=1;
        }

        num=num/10;
    }

    return 1;
}

int main()
{
    cin>>cntNums;

    long long num;
    for(long long i=0; i<cntNums; i++)
    {
        cin>>num;
        num++;

        while(!isAns(num))
        {
            if(num%10==0)num++;
            for(long long i=0; i<=9; i++)digs[i]=0;
            long long j=0, num1=num;
            num1=turn(num1);
            num=0;
            while(1)
            {
                long long lastDig=num1%10;
                num=num*10+lastDig;
                num1/=10;
                if(digs[lastDig]==1)
                {
                    j=lastDig;
                    num=num/10;
                    num1=num1*10+lastDig;
                    break;
                }
                digs[lastDig]=1;
            }

            while(num1>0)
            {
                long long lastDig=num1%10;
                num1=num1/10;
                bool p=false;
                for(long long i=j; i<=9; i++)
                {
                    if(digs[i]==0)
                    {
                        lastDig=i;
                        j=0;
                        p=true;
                        break;
                    }
                }

                if(p==false)
                {
                    num=num*10+10;
                    digs[0]=1;
                }
                else
                {
                    num=num*10+lastDig;
                    digs[lastDig]=1;
                }
            }
        }

        if(num<N)cout<<num<<endl;
        else cout<<"-1"<<endl;
    }

    return 0;
}
