#include<iostream>
using namespace std;
int nod(int a,int b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int l;
    cin>>l;
    int minr=l+1,mina=0,minb=0;
    bool p=false;
    for(int i=1;i<l/2;i++)
    {
        if(l%i==0)
        {
            int a,b;
            a=i;
            b=l/i;
            int nod1=nod(a,b);
            int nok=(a*b)/nod1;
            if(nok<=l && max(a,b)%min(a,b)!=0)
            {
                int raz=l/a-l/b;
                if(raz<minr)
                {
                    minr=raz;
                    mina=a;
                    minb=b;
                    p=true;
                }
            }
        }
    }
    if(p==false)cout<<"No solution"<<endl;
    else cout<<min(mina,minb)<<" "<<max(minb,mina)<<endl;
    return 0;
}
