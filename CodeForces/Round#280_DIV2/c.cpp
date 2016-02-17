#include<iostream>
#include<algorithm>
using namespace std;
struct exam
{
    long long grade;
    long long bre;
};
exam t[100000];
long long n, r, avg;
long long cmp1(exam s, exam t)
{
    if(s.bre!=t.bre)return s.bre<t.bre;
    else return s.grade<t.grade;
}
double average()
{
    long long sum=0;
    for(long long i=0; i<n; i++)
    {
        sum+=t[i].grade;
    }
    return (double)(sum/(double)(n));
}
int main()
{
    cin>>n>>r>>avg;
    long long totalGrades=n*avg;
    for(long long i=0; i<n; i++)
    {
        cin>>t[i].grade>>t[i].bre;
        totalGrades-=t[i].grade;
    }
    sort(t, t+n, cmp1);
    unsigned long long ind=0, sumE=0;
    while(totalGrades>0)
    {
        long long p=r-t[ind].grade;
        if(totalGrades-p>0)
        {
            totalGrades-=p;
            sumE+=p*t[ind].bre;
            ind++;
        }
        else
        {
            sumE+=totalGrades*t[ind].bre;
            break;
        }
    }
    cout<<sumE<<endl;
    return 0;
}
