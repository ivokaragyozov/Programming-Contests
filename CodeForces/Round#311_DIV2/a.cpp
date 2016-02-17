#include <iostream>
#define endl '\n'
using namespace std;

int n, min1, min2, min3, max1, max2, max3;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>min1>>max1>>min2>>max2>>min3>>max3;
}

int main()
{
    input();
    int sum = min1+min2+min3;
    if(sum<n)
    {
        if(sum-min1+max1<n)
        {
            sum += -min1+max1;
            cout<<max1<<" ";
        }
        else
        {
            cout<<min1+n-sum<<" "<<min2<<" "<<min3<<endl;
            return 0;
        }
        if(sum-min2+max2<n)
        {
            sum += -min2+max2;
            cout<<max2<<" ";
        }
        else
        {
            cout<<min2+n-sum<<" "<<min3<<endl;
            return 0;
        }
        if(sum-min3+max3<n)
        {
            sum += -min3+max3;
            cout<<max3<<endl;
        }
        else
        {
            cout<<min3+n-sum<<endl;
        }
    }
    else
    {
        cout<<min1<<" "<<min2<<" "<<min3<<endl;
    }
    return 0;
}
