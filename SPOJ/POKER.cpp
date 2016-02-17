#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int t, cards1[6];
char cardRank, cards1uit, buff;

int hashCard(char a, char b)
{
    int hashOfCard = 0;

    if(b == 'H') hashOfCard = 13;
    else if(b == 'D') hashOfCard = 26;
    else if(b == 'C') hashOfCard = 39;

    if(a == '3') hashOfCard += 1;
    else if(a == '4') hashOfCard += 2;
    else if(a == '5') hashOfCard += 3;
    else if(a == '6') hashOfCard += 4;
    else if(a == '7') hashOfCard += 5;
    else if(a == '8') hashOfCard += 6;
    else if(a == '9') hashOfCard += 7;
    else if(a == 'T') hashOfCard += 8;
    else if(a == 'J') hashOfCard += 9;
    else if(a == 'Q') hashOfCard += 10;
    else if(a == 'K') hashOfCard += 11;
    else if(a == 'A') hashOfCard += 12;

    return hashOfCard;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        for(int i = 0; i < 5; i++)
        {
            cin>>cardRank>>cards1uit;

            cards1[i] = hashCard(cardRank, cards1uit);
            cards1[i] = cards1[i] % 13;
        }

        sort(cards1, cards1 + 5);
        sort(cards1, cards1 + 5);

        for(int i = 0; i < 5; i++) cout<<cards1[i]<<" ";
        cout<<endl;


        if(cards1[0] == cards1[1] - 1 && cards1[0] == cards1[2] - 2 && cards1[0] == cards1[3] - 3 && cards1[0] == cards1[4] - 4 && cards1[4] % 13 == 12) cout<<"royal flush"<<endl;
        else if(cards1[0] == cards1[1] - 1 && cards1[0] == cards1[2] - 2 && cards1[0] == cards1[3] - 3 && cards1[0] == cards1[4] - 4 || cards1[0] - 1 == cards1[1] - 2 && cards1[0] - 1 == cards1[2] - 3 && cards1[0] - 1 == cards1[3] - 4 && cards1[0] - 1 == cards1[4] % 13) cout<<"straight flush"<<endl;
        else if((cards1[0] % 13 == cards1[1] % 13 && cards1[0] % 13 == cards1[2] % 13 && cards1[0] % 13 == cards1[3] % 13) || cards1[1] % 13 == cards1[2] % 13 && cards1[1] % 13 == cards1[3] % 13 && cards1[1] % 13 == cards1[4] % 13) cout<<"four of a kind"<<endl;
        else if((cards1[0] % 13 == cards1[1] % 13 && cards1[0] % 13 == cards1[2] % 13 && cards1[3] % 13 == cards1[4] % 13) || (cards1[0] % 13 == cards1[1] % 13 && cards1[2] % 13 == cards1[3] % 13 && cards1[2] % 13 == cards1[4] % 13)) cout<<"full house"<<endl;
        else if(cards1[0] / 13 == cards1[1] / 13 && cards1[0] / 13 == cards1[2] / 13 && cards1[0] / 13 == cards1[3] / 13 && cards1[0] / 13== cards1[4] / 13) cout<<"flush"<<endl;
        else if((cards1[0] % 13 == cards1[1] % 13 - 1 && cards1[0] % 13 == cards1[2] % 13 - 2 && cards1[0] % 13 == cards1[3] % 13 - 3 && cards1[0] % 13 == cards1[4] % 13 - 4) || (cards1[0] % 13 - 1 == cards1[1] % 13 - 2 && cards1[0] % 13 - 1 == cards1[2] % 13 - 3 && cards1[0] % 13 - 1 == cards1[3] % 13 - 4 && cards1[0] % 13 - 1 == cards1[4] % 13)) cout<<"straight"<<endl;
        else if((cards1[0] % 13 == cards1[1] % 13 && cards1[0] % 13 == cards1[2] % 13) || (cards1[2] % 13 == cards1[3] % 13 && cards1[2] % 13 == cards1[4] % 13)) cout<<"three of a kind"<<endl;
        else if((cards1[0] % 13 == cards1[1] % 13 && cards1[2] % 13 == cards1[3] % 13) || (cards1[0] % 13 == cards1[1] % 13 && cards1[3] % 13 == cards1[4] % 13) || (cards1[1] % 13 == cards1[2] % 13 && cards1[3] % 13 == cards1[4] % 13)) cout<<"two pairs"<<endl;
        else if(cards1[0] % 13 == cards1[1] % 13 || cards1[1] % 13 == cards1[2] % 13 || cards1[2] % 13 == cards1[3] % 13 || cards1[3] % 13 == cards1[4] % 13) cout<<"pair"<<endl;
        else cout<<"high card"<<endl;
    }

    return 0;
}
