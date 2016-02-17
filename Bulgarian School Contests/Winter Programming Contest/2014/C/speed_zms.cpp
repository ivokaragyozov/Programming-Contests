#include<iostream>
#include<algorithm>

using namespace std;

const int N=10005;

int gTownsCount, gRoadsCount, gAverageSpeed[N];

int main()
{
    cin>>gTownsCount>>gRoadsCount;

    int town1, town2;
    for(int i=0;i<gRoadsCount;i++)
    {
        cin>>town1>>town2;
        cin>>gAverageSpeed[i];
    }

    sort(gAverageSpeed, gAverageSpeed+gRoadsCount);

    int roadsoff=gRoadsCount-gTownsCount+1, sum=0;

    for(int i=0;i<roadoff;i++)
    {
        sum+=gAverageSpeed[i];
    }


    int p1=0, p2=0;

    for()
}
