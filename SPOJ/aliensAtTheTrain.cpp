#include <iostream>
#define endl '\n'
using namespace std;

int t, a, b, stations[100005], curNumber, curNumberPeople, maxNumber, startInd, seenPeople;

void init()
{
    curNumber = 0;
    maxNumber = 0;
    curNumberPeople = 0;
    startInd = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        init();

        cin>>a>>b;
        for(int i = 0; i < a; i++)
        {
            cin>>stations[i];

            curNumberPeople += stations[i];
            curNumber++;

            while(curNumberPeople > b)
            {
                curNumberPeople -= stations[startInd++];
                curNumber--;
            }

            if(curNumber > maxNumber || (curNumber == maxNumber && curNumberPeople < seenPeople))
            {
                maxNumber = curNumber;
                seenPeople = curNumberPeople;
            }
        }

        cout<<seenPeople<<" "<<maxNumber<<endl;
    }

    return 0;
}
