#include <iostream>
#define endl '\n'
using namespace std;

int year, day = 1, month = 1, m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, dayOfWeek, currList, needList, needDay, needMonth;
string firstJanuary, text, faces[400], backs[400];

bool isVisok(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return true;
    return false;
}
void nextDay(int &d, int &mon)
{
    d++;
    if(day > m[mon])
    {
        day = 1;
        mon++;
        if(month == 13) mon = 1;
    }
}
string daysOfWeek(int a)
{
    switch(a)
    {
        case 0: return "Monday";
        case 1: return "Tuesday";
        case 2: return "Wednesday";
        case 3: return "Thursday";
        case 4: return "Friday";
        case 5: return "Saturday";
        case 6: return "Sunday";
        default: return "";
    }
}
string toString(int a)
{
    string s;

    s = (char)((a / 10) + '0');
    s += (char)((a % 10) + '0');

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>year>>firstJanuary>>text;

    if(text != "Flip")
    {
        needDay = (text[0] - '0') * 10 + (text[1] - '0');
        needMonth = (text[3] - '0') * 10 + (text[4] - '0');
    }

    if(firstJanuary == "Monday") dayOfWeek = 0;
    else if(firstJanuary == "Tuesday") dayOfWeek = 1;
    else if(firstJanuary == "Wednesday") dayOfWeek = 2;
    else if(firstJanuary == "Thursday") dayOfWeek = 3;
    else if(firstJanuary == "Friday") dayOfWeek = 4;
    else if(firstJanuary == "Saturday") dayOfWeek = 5;
    else dayOfWeek = 6;

    if(isVisok(year))
    {
        m[2] = 29;
        while(1)
        {
            if(day == needDay && month == needMonth) needList = currList;

            if(day >= 3 && month == 7 && dayOfWeek != 5) break;

            faces[currList] += toString(day) + "." + toString(month) + " " + daysOfWeek(dayOfWeek);

            if(dayOfWeek == 5) faces[currList] += " ";
            else currList++;

            nextDay(day, month);
            dayOfWeek = (dayOfWeek + 1) % 7;
        }

        if(text == "Flip") needList = currList;
        faces[currList] = "Flip";

        while(day != 1 || month != 1)
        {
            if(day == needDay && month == needMonth) needList = currList;
            backs[currList] += toString(day) + "." + toString(month) + " " + daysOfWeek(dayOfWeek);

            if(dayOfWeek == 5) backs[currList] += " ";
            else currList--;

            nextDay(day, month);
            dayOfWeek = (dayOfWeek + 1) % 7;
        }
    }
    else
    {
        while(1)
        {
            if(day == needDay && month == needMonth) needList = currList;

            if(day >= 2 && month == 7 && dayOfWeek != 5) break;

            faces[currList] += toString(day) + "." + toString(month) + " " + daysOfWeek(dayOfWeek);

            if(dayOfWeek == 5) faces[currList] += " ";
            else currList++;

            nextDay(day, month);
            dayOfWeek = (dayOfWeek + 1) % 7;
        }

        if(text == "Flip") needList = currList;
        faces[currList] = "Flip";

        while(day != 1 || month != 1)
        {
            if(day == needDay && month == needMonth) needList = currList;
            backs[currList] += toString(day) + "." + toString(month) + " " + daysOfWeek(dayOfWeek);

            if(dayOfWeek == 5) backs[currList] += " ";
            else currList--;

            nextDay(day, month);
            dayOfWeek = (dayOfWeek + 1) % 7;
        }
    }

    cout<<"Face: "<<faces[needList]<<endl;
    cout<<"Back: "<<backs[needList]<<endl;
    return 0;
}
