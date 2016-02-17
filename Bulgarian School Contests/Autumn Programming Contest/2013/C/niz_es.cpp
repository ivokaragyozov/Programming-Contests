/**
Ivo Karagyozov
Esenen 2013 C2 niz
*/
#include<iostream>
#include<queue>

using namespace std;

int minzero=100000000, maxzero=0, typemin=0, typemax=0;

bool ispos(queue<int> q)
{
    bool one=false;
    int brone=0,brnull=0;
    int brzero=0, br1=0;
    minzero=100000000, maxzero=0, typemin=0, typemax=0;

    for(int i=0; i<q.size(); i++)
    {
        if(q.front()==1)
        {
            one=true;
            brone++;
            q.push(q.front());
            q.pop();
            br1++;
            if(brzero!=0)
            {
                if(brzero<minzero)
                {
                    typemin=0;
                    minzero=brzero;
                }
                if(brzero>maxzero)
                {
                    typemax=0;
                    maxzero=brzero;
                }
                if(brzero==minzero)typemin++;
                if(brzero==maxzero)typemax++;
                if(maxzero-minzero>1)return false;
            }
            brzero=0;
        }
        else
        {
            brzero++;
            br1=0;
            brnull++;
            q.push(q.front());
            q.pop();
        }

        if(br1==2)return false;
    }
    if(brzero!=0)
    {
        if(brzero<minzero)
        {
            typemin=0;
            minzero=brzero;
        }
        if(brzero>maxzero)
        {
            typemax=0;
            maxzero=brzero;
        }
        if(brzero==minzero)typemin++;
        if(brzero==maxzero)typemax++;
        if(maxzero-minzero>1)return false;
    }
    brzero=0;

    if(brone>brnull)return false;
    if(one==false)return false;
    return true;
}

int main()
{
    string s;
    cin>>s;
    queue<int> q;

    for(int i=0; i<s.size(); i++)
    {
        int a=s[i]-'0';
        q.push(a);
    }

    int brtimes=0;
    while(ispos(q))
    {
        brtimes++;
        if(typemin>typemax)
        {
            swap(typemin,typemax);
            swap(minzero,maxzero);
        }
        int brzero=0;

        int sizeq=q.size();
        for(int i=0; i<sizeq; i++)
        {
            if(q.front()==1)
            {
                if(brzero==maxzero)
                {
                    q.push(0);
                }
                else if(brzero==minzero)
                {
                    q.push(1);
                }
                brzero=0;
                q.pop();
            }
            else
            {
                brzero++;
                q.pop();
            }
        }
        if(brzero!=0)
        {
            if(brzero==maxzero)q.push(0);
            else if(brzero==minzero)q.push(1);
            brzero=0;
        }
        int qsize=q.size();
        for(int i=0; i<qsize; i++)
        {
            if(q.front()==1)break;
            q.push(q.front());
            q.pop();
        }
    }

    cout<<brtimes<<" ";
    for(int i=0; i<q.size(); i++)
    {
        cout<<q.front();
        q.push(q.front());
        q.pop();
    }

    cout<<endl;
    return 0;
}
