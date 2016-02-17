#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

char startPos[3], endPos[3];
int startPosI, startPosJ, endPosI, endPosJ;
vector<string> moves;

int letterToInt(char c)
{
    return c-'a'+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>startPos>>endPos;
    startPosJ = letterToInt(startPos[0]);
    startPosI = 8-(startPos[1]-'0')+1;

    endPosJ = letterToInt(endPos[0]);
    endPosI = 8-(endPos[1]-'0')+1;

    if(startPosI < endPosI)
    {
        if(startPosJ < endPosJ)
        {
            while(startPosI != endPosI && startPosJ != endPosJ)
            {
                moves.push_back("RD");
                startPosI++;
                startPosJ++;
            }
            //cout<<startPosI<<" "<<startPosJ<<" "<<endPosI<<" "<<endPosJ<<endl;
            if(startPosI != endPosI)
            {
                while(startPosI != endPosI)
                {
                    moves.push_back("D");
                    startPosI++;
                }
            }
            else
            {
                while(startPosJ != endPosJ)
                {
                    moves.push_back("R");
                    startPosJ++;
                }
            }
        }
        else if(startPosJ > endPosJ)
        {
            while(startPosI != endPosI && startPosJ != endPosJ)
            {
                moves.push_back("LD");
                startPosI++;
                startPosJ--;
            }
            if(startPosI != endPosI)
            {
                while(startPosI != endPosI)
                {
                    moves.push_back("D");
                    startPosI++;
                }
            }
            else
            {
                while(startPosJ != endPosJ)
                {
                    moves.push_back("L");
                    startPosJ--;
                }
            }
        }
        else
        {
            while(startPosI != endPosI)
            {
                moves.push_back("D");
                startPosI++;
            }
        }
    }
    else if(startPosI > endPosI)
    {
        if(startPosJ < endPosJ)
        {
            while(startPosI != endPosI && startPosJ != endPosJ)
            {
                moves.push_back("RU");
                startPosI--;
                startPosJ++;
            }
            if(startPosI != endPosI)
            {
                while(startPosI != endPosI)
                {
                    moves.push_back("U");
                    startPosI--;
                }
            }
            else
            {
                while(startPosJ != endPosJ)
                {
                    moves.push_back("R");
                    startPosJ++;
                }
            }
        }
        else if(startPosJ > endPosJ)
        {
            while(startPosI != endPosI && startPosJ != endPosJ)
            {
                moves.push_back("LU");
                startPosI--;
                startPosJ--;
            }
            if(startPosI != endPosI)
            {
                while(startPosI != endPosI)
                {
                    moves.push_back("U");
                    startPosI--;
                }
            }
            else
            {
                while(startPosJ != endPosJ)
                {
                    moves.push_back("L");
                    startPosJ--;
                }
            }
        }
        else
        {
            while(startPosI != endPosI)
            {
                moves.push_back("U");
                startPosI--;
            }
        }
    }
    else
    {
        if(startPosJ < endPosJ)
        {
            while(startPosJ != endPosJ)
            {
                moves.push_back("R");
                startPosJ++;
            }
        }
        else if(startPosJ > endPosJ)
        {
            while(startPosJ != endPosJ)
            {
                moves.push_back("L");
                startPosJ--;
            }
        }
    }
    cout<<moves.size()<<endl;
    for(int i = 0; i < moves.size(); i++)
    {
        cout<<moves[i]<<endl;
    }
}
