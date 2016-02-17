/**
Ivo Karagyozov
NOI1 2015 C1 sport
*/
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
queue<char> q, t;
bool isReady(queue<char> q)
{
    if(q.empty()==true)return true;
    while(1)
    {
        char a=q.front();
        q.pop();
        char b;
        if(q.empty()==false)b=q.front();
        else break;
        if(a=='L' && b=='R')return false;
    }
    return true;
}
void printQueue(queue<char> q)
{
    while(q.empty()==false)
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    cout<<endl;
}
void swapQueue()
{
    while(t.empty()==false)
    {
        q.push(t.front());
        t.pop();
    }
}
void delQueue()
{
    while(q.empty()==false)
    {
        q.pop();
    }
}
int main()
{
    string input;
    cin>>input;

    //A
    for(int i=0; i<input.size(); i++)
    {
        q.push(input[i]);
    }
    while(isReady(q)==false)
    {
        while(q.empty()==false)
        {
            char a=q.front();
            q.pop();
            char b;
            if(q.empty()==false)b=q.front();
            else
            {
                t.push(a);
                break;
            }
            if(a=='L' && b=='R')
            {
                q.pop();
            }
            else
            {
                t.push(a);
            }
        }
        swapQueue();
    }
    printf("%d\n", q.size());
    delQueue();

    //B
    for(int i=0; i<input.size(); i++)
    {
        q.push(input[i]);
    }
    while(isReady(q)==false)
    {
        char a=q.front();
        q.pop();
        char b=q.front();
        if(a=='L' && b=='R')
        {
            q.pop();
        }
        else
        {
            q.push(a);
        }
    }
    printf("%d\n", q.size());
    return 0;
}
