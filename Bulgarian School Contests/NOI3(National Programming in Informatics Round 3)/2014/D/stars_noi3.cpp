#include<iostream>
#include<vector>
using namespace std;
const int N=100005;
int x1,y1;
int r=x1+y1;
int main()
{
    int n;
    cin>>n;
    int a,b,c;
    vector<int> x,y;
    x.push_back(0);
    y.push_back(0);
    int minr=1000000;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            x.push_back(x[x.size()-1]+b);
            y.push_back(y[y.size()-1]+c);
        }
        else
        {
            cin>>b;
            x1=x[x.size()-1]-x[x.size()-1-b];
            y1=y[y.size()-1]-y[y.size()-1-b];
            x1=x1/b;
            y1=y1/b;
            if(x1<0)x1=x1*-1;
            if(y1<0)y1=y1*-1;
            r=x1+y1;
            if(r<minr)minr=r;
        }
    }
    cout<<minr<<endl;
    return 0;
}
