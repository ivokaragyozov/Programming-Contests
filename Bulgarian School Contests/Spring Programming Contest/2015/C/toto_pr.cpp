/**
Ivo Karagyozov
Proleten 2015 C3 toto
*/
#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>
#define endl '\n'
using namespace std;

int k, table[7][7], ind=0;
list<string> combins;
string ans, numbers[49]={"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49"};

void init()
{
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            table[i][j]=i*7+j+1;
        }
    }
}
int horse(int p, int ind)
{
    int i=(p-1)/7, j=(p-1)%7;
    if(ind==1 && i-2>=0 && j-1>=0)
    {
        return table[i-2][j-1];
    }
    else if(ind==2 && i-2>=0 && j+1<7)
    {
        return table[i-2][j+1];
    }
    else if(ind==3 && i-1>=0 && j+2<7)
    {
        return table[i-1][j+2];
    }
    else if(ind==4 && i+1<7 && j+2<7)
    {
        return table[i+1][j+2];
    }
    else if(ind==5 && i+2<7 && j+1<7)
    {
        return table[i+2][j+1];
    }
    else if(ind==6 && i+2<7 && j-1>=0)
    {
        return table[i+2][j-1];
    }
    else if(ind==7 && i+1<7 && j-2>=0)
    {
        return table[i+1][j-2];
    }
    else if(ind==8 && i-1>=0 && j-2>=0)
    {
        return table[i-1][j-2];
    }
    return 0;
}
string format(int nums[])
{
    string s="";

    sort(nums, nums+6);
    for(int i=0; i<6; i++)
    {
        s+=" "+numbers[nums[i]-1];
    }
    return s;
}
void generate_combins()
{
    int a, b, c, d, e, f, g;
    for(int i1=1; i1<=49; i1++)
    {
        a=i1;
        for(int i2=1; i2<9; i2++)
        {
            b=horse(a, i2);
            if(a==b || b==0)continue;
            for(int i3=1; i3<9; i3++)
            {
                c=horse(b, i3);
                if(a==c || b==c || c==0)continue;
                for(int i4=1; i4<9; i4++)
                {
                    d=horse(c, i4);
                    if(a==d || b==d || c==d || d==0)continue;
                    for(int i5=1; i5<9; i5++)
                    {
                        e=horse(d, i5);
                        if(a==e || b==e || c==e || d==e || e==0)continue;
                        for(int i6=1; i6<9; i6++)
                        {
                            f=horse(e, i6);
                            if(a==f || b==f || c==f || d==f || e==f || f==0)continue;
                            for(int i7=1; i7<9; i7++)
                            {
                                g=horse(f, i7);
                                if(a!=g || g==0)continue;
                                int nums[]={a, b, c, d, e, f};
                                string combin=format(nums);
                                if(find(combins.begin(), combins.end(), combin)==combins.end())
                                {
                                    combins.push_back(combin);
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k;
    init();
    generate_combins();
    combins.sort();
    for(int i=0; i<k-1; i++)
    {
        combins.pop_front();
    }
    ans=combins.front();
    for(int i=1; i<ans.size(); i++)
    {
        if(ans[i-1]==' ' && ans[i]=='0')
        {
            ans.replace(i-1, 2, " ");
        }
    }
    ans=ans.substr(1);
    cout<<ans<<endl;
    return 0;
}
