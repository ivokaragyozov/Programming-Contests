/**
Ivo Karagyozov
Esenen 2012 C1 timetable
*/
#include<iostream>

using namespace std;

int months[13]= {0, 0, 0, 0, 0, 0, 0, 0, -15, 15, 46, 76, 99};
int m[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dayToInt(string day)
{
    if(day=="Monday")return 1;
    else if(day=="Tuesday")return 2;
    else if(day=="Wednesday")return 3;
    else if(day=="Thursday")return 4;
    else if(day=="Friday")return 5;
    else if(day=="Saturday")return 6;
    else if(day=="Sunday")return 7;
}
int monthToInt(string month)
{
    if(month=="September")return 9;
    else if(month=="October")return 10;
    else if(month=="November")return 11;
    else if(month=="December")return 12;
}

string intToDay(int n)
{
    if(n==1)return "Monday";
    else if(n==2)return "Tuesday";
    else if(n==3)return "Wednesday";
    else if(n==4)return "Thursday";
    else if(n==5)return "Friday";
    else if(n==6)return "Saturday";
    else return "Sunday";
}

int main()
{
    string dayOf15;
    cin>>dayOf15;
    int dayOf15Int;
    dayOf15Int=(dayToInt(dayOf15)+1)%7;
    if(dayOf15Int==0)dayOf15Int=7;
    int dateOfTour;
    cin>>dateOfTour;

    string monthOfTour;
    cin>>monthOfTour;
    int monthOfTourInt;
    monthOfTourInt=monthToInt(monthOfTour);
    dateOfTour--;
    if(dateOfTour==0)
    {
        monthOfTourInt--;
        dateOfTour=m[monthOfTourInt];
    }

    int x,y;
    cin>>x>>y;

    int brTimesEachDay[8]= {0, 0, 0, 0, 0, 0, 0, 0}, brDays=0;
    brDays=months[monthOfTourInt-1]+dateOfTour;

    int type1=0, type2=0;

    for(int i=0; i<=6; i++)
    {
        int day=(dayOf15Int+i)%7;
        if(day==0)day=7;
        int brTimes=(brDays-i-1)/7+1;
        brTimesEachDay[day]=brTimes;
        if(type1==0)
        {
            type1=brTimes;
        }
        else
        {
            if(brTimes<type1)
            {
                type2=type1;
                type1=brTimes;
            }
            else if(brTimes>type1)
            {
                type2=brTimes;
            }
        }
    }

    int brTimesType1=0, brTimesType2=0;
    for(int i=1; i<=7; i++)
    {
        if(brTimesEachDay[i]==type1)brTimesType1++;
        else brTimesType2++;
    }
    if(brTimesType2==0)brTimesType2=8;


    int k=0,l=7;
    bool p=false;
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            int br=k*type1+l*type2;
            if(k<=brTimesType1 && l<=brTimesType2 && br>=x && br<=y)
            {
                p=true;
                break;
            }
            l--;
        }
        if(p==true)break;
        k++;
        l=7;
    }

    if(p==false)
    {
        cout<<0<<endl;
        return 0;
    }

    if(brTimesType2==8)l=0;
    cout<<k+l<<endl;

    for(int i=1; i<=7; i++)
    {
        if(brTimesEachDay[i]==type1 && k!=0)

        {
            cout<<intToDay(i)<<endl;
            k--;
        }
        else if(brTimesEachDay[i]==type2 && l!=0)
        {
            cout<<intToDay(i)<<endl;
            l--;
        }

        if(k==0 && l==0)return 0;
    }
}
