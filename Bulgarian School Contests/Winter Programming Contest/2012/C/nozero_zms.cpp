/**
Ivo Karagyozov
Zimni 2012 C2 nozero
*/
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n;
    long long sum=0;
    stack<int> st;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        if(a==0 && st.empty())
        {
            cout<<-1<<endl;
            return 0;
        }
        if(a==2)
        {
            st.push(i);
        }
        else
        {
            sum+=i-st.top();
            st.pop();
        }
    }
    cout<<sum<<endl;
    return 0;
}
