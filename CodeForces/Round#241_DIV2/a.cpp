#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;

char answer;
int n, number, lowerNum = -INT_MAX, upperNum = INT_MAX;
string type;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>type>>number>>answer;

        if(answer == 'N')
        {
            if(type == ">=") type = "<";
            else if(type == "<=") type = ">";
            else if(type == ">") type = "<=";
            else type = ">=";
        }


        if(type == ">=")
        {
            if(number > lowerNum) lowerNum = number;
        }
        else if(type == "<=")
        {
            if(number < upperNum) upperNum = number;
        }
        else if(type == ">")
        {
            if(number + 1 > lowerNum) lowerNum = number + 1;
        }
        else
        {
            if(number - 1 < upperNum) upperNum = number - 1;
        }
    }

    if(lowerNum <= upperNum)
    {
        if(upperNum != INT_MAX) cout<<upperNum<<endl;
        else if(lowerNum != -INT_MAX) cout<<lowerNum<<endl;
        else cout<<"Impossible"<<endl;
    }
    else cout<<"Impossible"<<endl;
    return 0;
}
