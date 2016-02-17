#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    bool p=false;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        int t=a*60+b;
        if(p==true)
        {
            sum+=t;
        }
        else
        {
            int brm=0;
            if(b>0)
            {
                brm=a+1;
            }
            else brm=a;
            if(brm>m)
            {
                sum+=t-m*60;
                m=0;
                p=true;
            }
            else m=m-brm;
        }
    }
    cout<<sum<<endl;
    return 0;
}
