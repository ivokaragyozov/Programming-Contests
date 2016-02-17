/**
Ivo Karagyozov
NOI3 2008 D1 expres
*/
#include<iostream>
using namespace std;
int main()
{
    int a[30];
    char z;
    int b,c,j=0;
    char d;
    cin>>b;
    cin.get(z);
    int sum=b;
    while(1)
    {
        cin>>b;
        if(z=='*')
        {
            a[j]=b*c;
            j++;
        }
        d=z;
        cin.get(z);
        if(z=='\n')
        {
            if(d=='+')
            {
                a[j]=b;
                j++;
            }
            break;
        }
        cin>>c;
        if(z=='*')
        {
            a[j]=b*c;
            j++;
        }
        d=z;
        cin.get(z);
        if(z=='\n')
        {
            if(d=='+')
            {
                a[j]=c;
                j++;
            }
            break;
        }
    }
    for(int i=0;i<j;i++)
    {
        sum=sum+a[i];
    }
    cout<<sum<<endl;
    return 0;
}
