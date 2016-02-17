#include <iostream>
#define endl '\n'
using namespace std;

bool vis[5][15];
int len, suit, number, cntP, cntK, cntH, cntT;
string s;
char p, x, y;

int suitToInt(char a)
{
    if(a == 'P') return 0;
    else if(a == 'K') return 1;
    else if(a == 'H') return 2;
    else return 3;
}
int numberToInt(char a, char b)
{
    return (a - '0') * 10 + (b - '0');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    len = s.size();
    for(int i = 0; i < len; i++)
    {
        p = s[i++];
        x = s[i++];
        y = s[i];

        suit = suitToInt(p);
        number = numberToInt(x, y);

        if(vis[suit][number])
        {
            cout<<"GRESKA"<<endl;
            return 0;
        }
        else vis[suit][number] = true;
    }

    for(int i = 1; i <= 13; i++)
    {
        if(!vis[0][i]) cntP++;
        if(!vis[1][i]) cntK++;
        if(!vis[2][i]) cntH++;
        if(!vis[3][i]) cntT++;
    }

    cout<<cntP<<" "<<cntK<<" "<<cntH<<" "<<cntT<<endl;
    return 0;
}
