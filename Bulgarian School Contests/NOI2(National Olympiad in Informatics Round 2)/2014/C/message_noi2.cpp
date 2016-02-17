/**
	Ivo Karagyozov
	NOI2 2014 C3 message
*/
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
string t;
stack<char> st;
int main()
{
	while(1)
	{
		char a;
		cin.get(a);
		if(a=='\n')break;
		if(!st.empty() && st.top()==a)st.pop();
		else st.push(a);
	}
	while(!st.empty())
	{
		t+=st.top();
		st.pop();
	}
	reverse(t.begin(), t.end());
	cout<<t<<endl;
	return 0;
}
