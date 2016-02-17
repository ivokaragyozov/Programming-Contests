#include<iostream>
using namespace std;
int toten(string a)
{
    int p=1,sum=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        int dig=0;
        if(isalpha(a[i]))dig=(int)(a[i]-'A')+10;
        else dig=(int)(a[i]-'0');
        sum=sum+p*dig;
        p=p*15;
    }
    return sum;
}
bool k[60];
int main()
{
    int a,b,c,d;
    string s;
    getline(cin,s);
    if(isdigit(s[0]))
    {
        a=s[0]-'0';
    }
    else
    {
        a=s[0]-'A'+10;
    }
    if(isdigit(s[1]))
    {
        b=s[1]-'0';
    }
    else
    {
        b=s[1]-'A'+10;
    }
    if(isdigit(s[2]))
    {
        c=s[2]-'0';
    }
    else
    {
        c=s[2]-'A'+10;
    }
    if(isdigit(s[3]))
    {
        d=s[3]-'0';
    }
    else
    {
        d=s[3]-'A'+10;
    }
    int p=0;
    for(int i=4;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            p=p*10+(int)(s[i]-'0');
        }
        else
        {
            p=p*10+(int)(s[i]-'A'+10);
        }
    }
    int q[20][20];
    q[0][0]=0;
    q[1][0]=0;q[1][1]=1;q[1][2]=3;q[1][3]=5;q[1][4]=7;q[1][5]=9;q[1][6]=11;q[1][7]=13;
    q[2][0]=0;q[2][1]=2;q[2][2]=3;q[2][3]=6;q[2][4]=7;q[2][5]=10;q[2][6]=11;q[2][7]=14;
    q[3][0]=0;q[3][1]=3;q[3][2]=7;q[3][3]=11;
    q[4][0]=0;q[4][1]=4;q[4][2]=5;q[4][3]=6;q[4][4]=7;q[4][5]=12;q[4][6]=13;q[4][7]=14;
    q[5][0]=0;q[5][1]=5;q[5][2]=7;q[5][3]=13;
    q[6][0]=0;q[6][1]=6;q[6][2]=7;q[6][3]=14;
    q[7][0]=0;q[7][1]=7;
    q[8][0]=0;q[8][1]=8;q[8][2]=9;q[8][3]=10;q[8][4]=11;q[8][5]=12;q[8][6]=13;q[8][7]=14;
    q[9][0]=0;q[9][1]=9;q[9][2]=11;q[9][3]=13;
    q[10][0]=0;q[10][1]=10;q[10][2]=11;q[10][3]=14;
    q[11][0]=0;q[11][1]=11;
    q[12][0]=0;q[12][1]=12;q[12][2]=13;q[12][3]=14;
    q[13][0]=0;q[13][1]=13;
    q[14][0]=0;q[14][1]=14;
    int t[20]={1,8,8,4,8,4,4,2,8,4,4,2,4,2,2};
    if(p>=10)
    {
        for(int i=1;i<t[p/10];i++)
        {
            for(int j=0;j<t[p%10];j++)
            {
                string x="";
                if(q[p/10][i]<10)x=x+((char)(q[p/10][i]+'0'));
                else x=x+((char)((q[p/10][i]-10)+'A'));
                if(q[p%10][j]<10)x=x+((char)(q[p%10][j]+'0'));
                else x=x+((char)((q[p%10][j]-10)+'A'));
                int y=toten(x);
                if(y<=56)
                {
                    k[y]=true;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<t[p];i++)
        {
            string z;
            z=z+(char)(q[p][i]+'0');
            k[toten(z)]=true;
        }
    }
    int br=0;
    for(int i=0;i<t[a];i++)
    {
        for(int j=0;j<t[b];j++)
        {
            for(int x=0;x<t[c];x++)
            {
                for(int y=0;y<t[d];y++)
                {

                    if(k[q[a][i]+q[b][j]+q[c][x]+q[d][y]]==true && k[q[a][i]+q[b][j]+q[c][x]+q[d][y]]!=0)
                    {
                        br++;
                    }
                }
            }
        }
    }
    cout<<br<<endl;
    return 0;
}
