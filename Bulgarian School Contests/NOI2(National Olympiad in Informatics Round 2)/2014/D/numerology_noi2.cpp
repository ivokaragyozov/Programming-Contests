/**
Ivo Karagyozov
NOI2 2014 D2 numerology
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
long long sumd(long long sum)
{
    long long s=0;
    while(sum>0)
    {
        s+=sum%10;
        sum=sum/10;
    }
    return s;
}
int main()
{
   string s;
   long long sum=0;
   getline(cin,s);
   for(int i=0;i<s.size();i++)
   {
       s[i]=tolower(s[i]);
       if(s[i]=='a' || s[i]=='j' || s[i]=='s')sum+=1;
       else if(s[i]=='b' || s[i]=='k' || s[i]=='t')sum+=2;
       else if(s[i]=='c' || s[i]=='l' || s[i]=='u')sum+=3;
       else if(s[i]=='d' || s[i]=='m' || s[i]=='v')sum+=4;
       else if(s[i]=='e' || s[i]=='n' || s[i]=='w')sum+=5;
       else if(s[i]=='f' || s[i]=='o' || s[i]=='x')sum+=6;
       else if(s[i]=='g' || s[i]=='p' || s[i]=='y')sum+=7;
       else if(s[i]=='h' || s[i]=='q' || s[i]=='z')sum+=8;
       else if(s[i]=='i' || s[i]=='r')sum+=9;
   }
   while(sum>=10)
   {
        if(sum==33)
        {
            cout<<sum<<endl;
            return 0;
        }
        sum=sumd(sum);
   }
   cout<<sum<<endl;
   return 0;
}
