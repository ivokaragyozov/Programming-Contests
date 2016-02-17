#include <iostream>
#include <cmath>
#include <iomanip>
#define endl '\n'
using namespace std;

int j, number, curX, curY;
double answer;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, s);

    int len = s.size();
    for(int i = 0; i < len; i++)
    {
        if(s[i] == 's' || s[i] == 'w' || s[i] == 'n' || s[i] == 'e')
        {
            j = i+1;
            number = 0;
            while(s[j] <= '9' && s[j] >= '0')
            {
                number = number*10+(s[j]-'0');
                j++;
            }

            if(s[i] == 'n') curY += number;
            else if(s[i] == 'e') curX += number;
            else if(s[i] == 's') curY -= number;
            else curX -= number;

            i = j-1;
        }
    }

    answer = sqrt(curX*curX+curY*curY);
    cout<<fixed<<setprecision(2)<<answer<<endl;
    return 0;
}
