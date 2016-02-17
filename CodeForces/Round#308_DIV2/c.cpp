#include <iostream>
#define endl '\n'
using namespace std;

int n, x[2005], y[2005], cnt=0;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i];
    }
}
int det(int a1, int b1, int a2, int b2, int a3, int b3)
{
    return (a1*b2+b1*a3+a2*b3)-(a3*b2+b3*a1+a2*b1);
}

int main()
{
    input();
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(det(x[i], y[i], x[j], y[j], x[k], y[k])!=0)
                {
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
