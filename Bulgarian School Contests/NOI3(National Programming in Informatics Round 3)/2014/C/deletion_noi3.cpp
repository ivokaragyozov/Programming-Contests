#include<iostream>
#include<vector>
using namespace std;

vector<int> two, zero, one, four;
int n, indzero, indone, indfour;
long long pos=0, ans=0;

int turn(int i)
{
    int m=0;
    while(i>0)
    {
        m=m*10+i%10;
        i/=10;
    }
    return m;
}
int len(int i)
{
    int br=0;
    while(i>0)
    {
        br++;
        i/=10;
    }
    return br;
}
int binarySZero(int target)
{
    int le=0, ri=zero.size()-1, nr=0;
    while(le<=ri)
    {
        int mid=(le+ri)/2;
        if(zero[mid]>target)
        {
            ri=mid-1;
            nr=mid;
        }
        else if(zero[mid]<target)le=mid+1;
        else return mid;
    }
    return nr;
}
int binarySOne(int target)
{
    int le=0, ri=one.size()-1, nr=0;
    while(le<=ri)
    {
        int mid=(le+ri)/2;
        if(one[mid]>target)
        {
            ri=mid-1;
            nr=mid;
        }
        else if(one[mid]<target)le=mid+1;
        else return mid;
    }
    return nr;
}
int binarySFour(int target)
{
    int le=0, ri=four.size()-1, nr=0;
    while(le<=ri)
    {
        int mid=(le+ri)/2;
        if(four[mid]>target)
        {
            ri=mid-1;
            nr=mid;
        }
        else if(four[mid]<target)le=mid+1;
        else return mid;
    }
    return nr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int num=turn(i), length=len(i), length_of_num=len(num);
        while(num>0)
        {
            if(num%10==2)two.push_back(pos);
            else if(num%10==0)zero.push_back(pos);
            else if(num%10==1)one.push_back(pos);
            else if(num%10==4)four.push_back(pos);
            num/=10;
            pos++;
        }
        while(length_of_num<length)
        {
            zero.push_back(pos);
            pos++;
            length_of_num++;
        }
    }
    for(int i=0; i<two.size(); i++)
    {
        indzero=binarySZero(two[i]);
        if(zero[indzero]<two[i])break;
        for(int j=indzero; j<zero.size(); j++)
        {
            indone=binarySOne(zero[j]);
            if(one[indone]<zero[indzero])break;
            for(int p=indone; p<one.size(); p++)
            {
                indfour=binarySFour(one[p]);
                if(four[indfour]<one[indone])break;
                ans+=four.size()-indfour;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
