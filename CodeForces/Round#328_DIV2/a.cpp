#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

int minW = 10, minB = 10;
bool columns[8];
char a[10][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cin>>a[i][j];

            if(a[i][j] == 'W')
            {
                if(!columns[j])
                {
                    if(i + 1 < minW) minW = i + 1;
                }
            }
            else if(a[i][j] == 'B')
            {
                columns[j] = true;
            }
        }
    }

    memset(columns, 0, sizeof(columns));

    for(int i = 7; i >= 0; i--)
    {
        for(int j = 7; j >= 0; j--)
        {
            if(a[i][j] == 'B')
            {
                if(!columns[j])
                {
                    if(8 - i < minB) minB = 8 - i;
                }
            }
            else if(a[i][j] == 'W')
            {
                columns[j] = true;
            }
        }
    }

    if(minW <= minB) cout<<"A"<<endl;
    else cout<<"B"<<endl;
    return 0;
}
