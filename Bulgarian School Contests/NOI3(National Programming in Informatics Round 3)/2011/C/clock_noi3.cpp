/**
Ivo Karagyozov
NOI3 2011 C1 clock
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#define endl '\n'
using namespace std;

double hour, minutes, angleMinutes, angleHour, angle1, angle2, angle3;
char buffer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>hour>>buffer>>minutes;
    angleMinutes = minutes*6;
    angleHour = hour*30 + minutes*0.5;
    angle1 = abs(angleHour-angleMinutes);
    angle2 = 360-angleHour+angleMinutes;
    angle3 = angleHour+360-angleMinutes;
    cout<<fixed<<setprecision(3);
    cout<<min(angle1, min(angle2, angle3))<<endl;
    return 0;
}
