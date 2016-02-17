#include<iostream>
#include<algorithm>
using namespace std;

int a[100005];
long long sum=0;

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a, a+n, cmp);
    for(int i=0; i<n; )
    {
        int s1=0, s2, s3, s4, s5;
        if(i+3>n)break;
        s5=a[i];
        s4=a[i+1];
        s3=a[i+2];
        s2=a[i+3];
        if(i+4<n)s1=a[i+4];
        if((s5==s4 || s5-1==s4) && (s3==s2 || s3-1==s2))
        {
            sum+=(long long)s4*(long long)s2;
            i+=4;
        }
        else if((s5!=s4 && s5-1!=s4) && (s4==s3 || s4-1==s3) && (s2==s1 || s2-1==s1))
        {
            sum+=(long long)s3*(long long)s1;
            i+=5;
        }
        else i++;
    }
    cout<<sum<<endl;
    return 0;
}
