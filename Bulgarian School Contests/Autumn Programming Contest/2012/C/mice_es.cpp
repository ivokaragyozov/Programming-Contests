/**
Ivo Karagyozov
Esenen 2012 C2 mice
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int cmp(int a, int b)
{
    return a>b;
}

int RightA(queue<int> lineRight)
{
    int s=lineRight.size();
    int brm=0;
    for(int i=0; i<s; i++)
    {
        if(lineRight.front()==2)
        {
            if(brm!=0)brm--;
        }
        else
        {
            brm++;
        }
        lineRight.pop();
    }
    return brm;
}

int LeftA(queue<int> lineLeft)
{
    int s=lineLeft.size();
    int brm=0;
    for(int i=0; i<s; i++)
    {
        if(lineLeft.front()==2)
        {
            if(brm!=0)brm--;
        }
        else
        {
            brm++;
        }
        lineLeft.pop();
    }
    return brm;
}

int RightB(queue<int> lineRight)
{
    int s=lineRight.size();
    int brm=0;
    for(int i=0; i<s; )
    {
        if(lineRight.front()==1)
        {
            bool p=false;
            while(1)
            {
                i++;
                lineRight.pop();
                if(lineRight.front()==1 || i==s)break;
                p=true;
            }
            if(p==false)
            {
                brm++;
            }
        }
        else
        {
            i++;
            lineRight.pop();
        }
    }
    return brm;
}

int LeftB(queue<int> lineLeft)
{
    int brm=0;
    int s=lineLeft.size();
    for(int i=0; i<s;)
    {
        if(lineLeft.front()==1)
        {
            bool p=false;
            while(1)
            {
                i++;
                lineLeft.pop();
                if(lineLeft.front()==1 || i==s)break;
                p=true;
            }
            if(p==false)
            {
                brm++;
            }
        }
        else
        {
            lineLeft.pop();
            i++;
        }
    }
    return brm;
}

int main()
{
    int brMouse=0;
    cin>>brMouse;

    queue<int> lineRight;
    queue<int> lineLeft;

    vector<int> mouseRight;
    vector<int> mouseLeft;
    for(int i=0; i<brMouse; i++)
    {
        int pos;
        cin>>pos;
        mouseRight.push_back(pos);
        mouseLeft.push_back(pos);
    }

    int brCheese=0;
    cin>>brCheese;

    vector<int> cheeseRight;
    vector<int> cheeseLeft;
    for(int i=0; i<brCheese; i++)
    {
        int pos;
        cin>>pos;
        cheeseRight.push_back(pos);
        cheeseLeft.push_back(pos);
    }

    sort(mouseRight.begin(), mouseRight.end());
    sort(mouseLeft.begin(), mouseLeft.end(), cmp);
    sort(cheeseRight.begin(), cheeseRight.end());
    sort(cheeseLeft.begin(), cheeseLeft.end(), cmp);

    int p=0, q=0;
    while(p!=brMouse || q!=brCheese)
    {
        if(p==brMouse)
        {
            lineRight.push(2);
            q++;
        }
        else if(q==brCheese)
        {
            lineRight.push(1);
            p++;
        }
        else
        {
            if(mouseRight[p]<=cheeseRight[q])
            {
                lineRight.push(1);
                p++;
            }
            else
            {
                lineRight.push(2);
                q++;
            }
        }
    }

    p=0,q=0;
    while(p!=brMouse || q!=brCheese)
    {
        if(p==brMouse)
        {
            lineLeft.push(2);
            q++;
        }
        else if(q==brCheese)
        {
            lineLeft.push(1);
            p++;
        }
        else
        {
            if(mouseLeft[p]>=cheeseLeft[q])
            {
                lineLeft.push(1);
                p++;
            }
            else
            {
                lineLeft.push(2);
                q++;
            }
        }
    }

    int brmRightA=RightA(lineRight);
    int brmLeftA=LeftA(lineLeft);
    int brmRightB=RightB(lineRight);
    int brmLeftB=LeftB(lineLeft);

    if(brmRightA<brmLeftA)
    {
        cout<<"R "<<brmRightA;
    }
    else if(brmRightA>brmLeftA)cout<<"L "<<brmLeftA;
    else cout<<"D "<<brmRightA;
    cout<<endl;

    if(brmRightB<brmLeftB)
    {
        cout<<"R "<<brmRightB;
    }
    else if(brmRightB>brmLeftB)
    {
        cout<<"L "<<brmLeftB;
    }
    else cout<<"D "<<brmRightB;
    cout<<endl;

    return 0;
}
