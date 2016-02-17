/**
Ivo Karagyozov
Zimni 2012 C1 puzzles
*/
#include<iostream>
#include<cstdio>
using namespace std;

int toInt(string s)
{
    int res = 0;
    for(int i=0; i<s.size(); i++)
    {
        res = res*10 + (s[i]-'0');
    }
    return res;
}
int sizeOf(int num)
{
    int br=0;
    while(num>0)
    {
        num=num/10;
        br++;
    }
    return br;
}

int main()
{
    char input[20];
    scanf("%s", input);
    string num1, num2, num3;
    int k=0;
    char let[5], ind=0;
    for(int i=0; ; i++)
    {
        if(input[i] == '\0')break;
        if(input[i] == '+' || input[i] == '=')
        {
            k++;
            continue;
        }
        bool p = false;
        for(int j=0; j<ind; j++)
        {
            if(let[j] == input[i])
            {
                p=true;
                break;
            }
        }
        if(p==false && !(input[i]>='0' && input[i]<='9'))
        {
            let[ind]=input[i];
            ind++;
        }
        if(k==0)num1 = num1+input[i];
        else if(k==1)num2 = num2+input[i];
        else num3 = num3+input[i];
    }
    int br = 0;
    if(ind==0)br=1;
    else if(ind==1)
    {
        for(int a=0; a<10; a++)
        {
            string num11 = num1, num12 = num2, num13 = num3;
            for(int i=0; i<num11.size(); i++)
            {
                if(num11[i] == let[0])num11[i] = (char)(a+'0');
            }
            for(int i=0; i<num12.size(); i++)
            {
                if(num12[i] == let[0])num12[i] = (char)(a+'0');
            }
            for(int i=0; i<num13.size(); i++)
            {
                if(num13[i] == let[0])num13[i] = (char)(a+'0');
            }
            int num21, num22, num23;
            num21 = toInt(num11);
            num22 = toInt(num12);
            num23 = toInt(num13);
            if(num21 + num22 == num23)br++;
        }
    }
    else if(ind==2)
    {
        for(int a=0; a<10; a++)
        {
            for(int b=0; b<10; b++)
            {
                if(a==b)continue;
                string num11 = num1, num12 = num2, num13 = num3;
                for(int i=0; i<num11.size(); i++)
                {
                    if(num11[i] == let[0])num11[i] = (char)(a+'0');
                    else if(num11[i] == let[1])num11[i] = (char)(b+'0');
                }
                for(int i=0; i<num12.size(); i++)
                {
                    if(num12[i] == let[0])num12[i] = (char)(a+'0');
                    else if(num12[i] == let[1])num12[i] = (char)(b+'0');
                }
                for(int i=0; i<num13.size(); i++)
                {
                    if(num13[i] == let[0])num13[i] = (char)(a+'0');
                    else if(num13[i] == let[1])num13[i] = (char)(b+'0');
                }
                int num21, num22, num23;
                num21 = toInt(num11);
                num22 = toInt(num12);
                num23 = toInt(num13);
                if(num21 + num22 == num23)br++;
            }
        }
    }
    else if(ind==3)
    {
        for(int a=0; a<10; a++)
        {
            for(int b=0; b<10; b++)
            {
                for(int c=0; c<10; c++)
                {
                    if(a==b || a==c || b==c)continue;
                    string num11 = num1, num12 = num2, num13 = num3;
                    for(int i=0; i<num11.size(); i++)
                    {
                        if(num11[i] == let[0])num11[i] = (char)(a+'0');
                        else if(num11[i] == let[1])num11[i] = (char)(b+'0');
                        else if(num11[i] == let[2])num11[i] = (char)(c+'0');
                    }
                    for(int i=0; i<num12.size(); i++)
                    {
                        if(num12[i] == let[0])num12[i] = (char)(a+'0');
                        else if(num12[i] == let[1])num12[i] = (char)(b+'0');
                        else if(num12[i] == let[2])num12[i] = (char)(c+'0');
                    }
                    for(int i=0; i<num13.size(); i++)
                    {
                        if(num13[i] == let[0])num13[i] = (char)(a+'0');
                        else if(num13[i] == let[1])num13[i] = (char)(b+'0');
                        else if(num13[i] == let[2])num13[i] = (char)(c+'0');
                    }
                    int num21, num22, num23;
                    num21 = toInt(num11);
                    num22 = toInt(num12);
                    num23 = toInt(num13);
                    if(num21 + num22 == num23)br++;
                }
            }
        }
    }
    else if(ind==4)
    {
        for(int a=0; a<10; a++)
        {
            for(int b=0; b<10; b++)
            {
                for(int c=0; c<10; c++)
                {
                    for(int d=0; d<10; d++)
                    {
                        if(a==b || a==c || a==d || b==c || b==d || c==d)continue;
                        string num11 = num1, num12 = num2, num13 = num3;
                        for(int i=0; i<num11.size(); i++)
                        {
                            if(num11[i] == let[0])num11[i] = (char)(a+'0');
                            else if(num11[i] == let[1])num11[i] = (char)(b+'0');
                            else if(num11[i] == let[2])num11[i] = (char)(c+'0');
                            else if(num11[i] == let[3])num11[i] = (char)(d+'0');
                        }
                        for(int i=0; i<num12.size(); i++)
                        {
                            if(num12[i] == let[0])num12[i] = (char)(a+'0');
                            else if(num12[i] == let[1])num12[i] = (char)(b+'0');
                            else if(num12[i] == let[2])num12[i] = (char)(c+'0');
                            else if(num12[i] == let[3])num12[i] = (char)(d+'0');
                        }
                        for(int i=0; i<num13.size(); i++)
                        {
                            if(num13[i] == let[0])num13[i] = (char)(a+'0');
                            else if(num13[i] == let[1])num13[i] = (char)(b+'0');
                            else if(num13[i] == let[2])num13[i] = (char)(c+'0');
                            else if(num13[i] == let[3])num13[i] = (char)(d+'0');
                        }
                        int num21, num22, num23;
                        num21 = toInt(num11);
                        num22 = toInt(num12);
                        num23 = toInt(num13);
                        if(sizeOf(num21) != num11.size() || sizeOf(num22) != num12.size() || sizeOf(num23) != num13.size())continue;
                        if(num21 + num22 == num23)br++;
                    }
                }
            }
        }
    }
    else if(ind == 5)
    {
        for(int a=0; a<10; a++)
        {
            for(int b=0; b<10; b++)
            {
                for(int c=0; c<10; c++)
                {
                    for(int d=0; d<10; d++)
                    {
                        for(int e=0; e<10; e++)
                        {
                            if(a==b || a==c || a==d || a==e || b==c || b==d || b==e || c==d || c==e || d==e)continue;
                            string num11 = num1, num12 = num2, num13 = num3;
                            for(int i=0; i<num11.size(); i++)
                            {
                                if(num11[i] == let[0])num11[i] = (char)(a+'0');
                                else if(num11[i] == let[1])num11[i] = (char)(b+'0');
                                else if(num11[i] == let[2])num11[i] = (char)(c+'0');
                                else if(num11[i] == let[3])num11[i] = (char)(d+'0');
                                else if(num11[i] == let[4])num11[i] = (char)(e+'0');
                            }
                            for(int i=0; i<num12.size(); i++)
                            {
                                if(num12[i] == let[0])num12[i] = (char)(a+'0');
                                else if(num12[i] == let[1])num12[i] = (char)(b+'0');
                                else if(num12[i] == let[2])num12[i] = (char)(c+'0');
                                else if(num12[i] == let[3])num12[i] = (char)(d+'0');
                                else if(num12[i] == let[4])num12[i] = (char)(e+'0');
                            }
                            for(int i=0; i<num13.size(); i++)
                            {
                                if(num13[i] == let[0])num13[i] = (char)(a+'0');
                                else if(num13[i] == let[1])num13[i] = (char)(b+'0');
                                else if(num13[i] == let[2])num13[i] = (char)(c+'0');
                                else if(num13[i] == let[3])num13[i] = (char)(d+'0');
                                else if(num13[i] == let[4])num13[i] = (char)(e+'0');
                            }
                            int num21, num22, num23;
                            num21 = toInt(num11);
                            num22 = toInt(num12);
                            num23 = toInt(num13);
                            if(num21 + num22 == num23)br++;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", br);
    return 0;
}
