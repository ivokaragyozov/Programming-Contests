#include <iostream>
#define endl '\n'
using namespace std;

string num1, num2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>num1>>num2;

    int len = num1.size();
    for(int i = 0; i < len; i++)
    {
        if(num1[i] != num2[i]) cout<<1;
        else cout<<0;
    }

    cout<<endl;
    return 0;
}
