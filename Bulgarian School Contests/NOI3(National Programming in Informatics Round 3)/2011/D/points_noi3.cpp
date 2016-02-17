/**
Ivo Karagyozov
NOI3 2011 D4 points
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[20][20];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    int b[20];
    int total=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            b[j]=a[i][j];
        }
        sort(b,b+n);
        int br=0;
        for(int j=1; j<n; j++)
        {
            int br1=1;
            while(b[j-1]+1==b[j])
            {
                br1++;
                j++;
            }
            if(br1!=1)br+=br1;
        }
        if(br==2)total+=10;
        else if(br==3)total+=40;
        else if(br==4)total+=70;
        else if(br==5)total+=100;
        else if(br>5)total+=150;
    }
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n; i++)
        {
            b[i]=a[i][j];
        }
        sort(b,b+n);
        int br=0;
        for(int i=1; i<n; i++)
        {
            int br1=1;
            while(b[i-1]+1==b[i])
            {
                i++;
                br1++;
            }
            if(br1!=1)br+=br1;
        }
        if(br==2)total+=20;
        else if(br==3)total+=50;
        else if(br==4)total+=80;
        else if(br==5)total+=110;
        else if(br>5)total+=160;
    }
    for(int i=0; i<n; i++)
    {
        b[i]=a[i][i];
    }
    sort(b,b+n);
    int br=0;
    for(int j=1; j<n; j++)
    {
        int br1=1;
        while(b[j-1]+1==b[j])
        {
            br1++;
            j++;
        }
        if(br1!=1)br+=br1;
    }
    if(br==2)total+=30;
    else if(br==3)total+=60;
    else if(br==4)total+=90;
    else if(br==5)total+=120;
    else if(br>5)total+=170;
    for(int i=0,j=n-1; i<n; i++,j--)
    {
        b[i]=a[i][j];
    }
    sort(b,b+n);
    br=0;
    for(int j=1; j<n; j++)
    {
        int br1=1;
        while(b[j-1]+1==b[j])
        {
            j++;
            br1++;
        }
        if(br1!=1)br+=br1;
    }
    if(br==2)total+=30;
    else if(br==3)total+=60;
    else if(br==4)total+=90;
    else if(br==5)total+=120;
    else if(br>5)total+=170;
    cout<<total<<endl;
    return 0;
}
