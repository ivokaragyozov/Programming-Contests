#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e6;

long long n, a[maxN], curr, maxArea, currArea;
stack<int> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];

        if(st.empty() || a[i] >= a[st.top()]) st.push(i);
        else
        {
            while(!st.empty() && a[st.top()] > a[i])
            {
                curr = st.top();
                st.pop();

                currArea = a[curr] * (st.empty() ? i : i - st.top() - 1);

                if(currArea > maxArea) maxArea = currArea;
            }

            st.push(i);
        }
    }

    while(!st.empty())
    {
        curr = st.top();
        st.pop();

        currArea = a[curr] * (st.empty() ? n : n - st.top() - 1);

        if(currArea > maxArea) maxArea = currArea;
    }

    cout<<maxArea<<endl;
    return 0;
}
