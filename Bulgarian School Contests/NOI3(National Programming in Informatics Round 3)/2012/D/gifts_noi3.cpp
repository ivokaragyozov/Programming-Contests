/**
Ivo Karagyozov
NOI3 2012 D4 gifts
*/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    stack<int> st1,st2,st3;
    queue<int> qu;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        st1.push(i);
    }
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        qu.push(a);
    }
    string s;
    while(st2.size()!=0 || st1.size()!=0)
    {
        if(st2.size()!=0)
        {
            if(st2.top()==qu.front())
            {

                qu.pop();
                st2.pop();
                s=s+'2';
            }
            else
            {
                bool p=false;
                while(st2.size()!=0)
                {
                    st3.push(st2.top());
                    if(st3.top()==qu.front())p=true;
                    st2.pop();
                }
                while(st3.size()!=0)
                {
                    st2.push(st3.top());
                    st3.pop();
                }
                if(p==true)
                {
                    while(st2.top()!=qu.front())
                    {
                        st1.push(st2.top());
                        st2.pop();
                        s=s+'3';
                    }
                    qu.pop();
                    st2.pop();
                    s=s+'2';
                }
                else
                {
                    while(st2.top()!=qu.front())
                    {
                        st2.push(st1.top());
                        st1.pop();
                        s=s+'1';
                    }
                    st2.pop();
                    qu.pop();
                    s=s+'2';
                }
            }
        }
        else
        {
            st2.push(st1.top());
            st1.pop();
            s=s+'1';
        }
    }
    cout<<s<<endl;
    return 0;
}
