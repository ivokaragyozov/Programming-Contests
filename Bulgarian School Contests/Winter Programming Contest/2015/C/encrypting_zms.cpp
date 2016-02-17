/**
Ivo Karagyozov
Zimni 2015 C1 encryption
*/
#include <iostream>
#define endl '\n'
using namespace std;

string message, words[10005];
int wordInd = 0;

string decodeWord(string word)
{
    string decodedWord = "";
    for(int i=0, j=word.size()-1; i<=j; i++, j--)
    {
        if(word.size()%2 != 0)
        {
            swap(i, j);
        }
        decodedWord = word[i] + decodedWord;
        if(i != j)
        {
            decodedWord = word[j] + decodedWord;
        }
        if(word.size()%2 != 0)
        {
            swap(i, j);
        }
    }
    return decodedWord;
}
string decodeMessage(string s[])
{
    string decodedMessage = "";
    for(int i=0, j=wordInd; i<=j; i++, j--)
    {
        if((wordInd+1)%2 != 0)
        {
            swap(i, j);
        }
        decodedMessage = " "+s[i]+decodedMessage;
        if(i != j)
        {
            decodedMessage = " "+s[j]+decodedMessage;
        }
        if(i>j)
        {
            swap(i, j);
        }
    }
    return decodedMessage;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, message);
    for(int i=0; i<message.size(); i++)
    {
        if(message[i] == ' ')
        {
            wordInd++;
        }
        else
        {
            words[wordInd] += message[i];
        }
    }

    for(int i=0; i<=wordInd; i++)
    {
        words[i] = decodeWord(words[i]);
    }
    string decodedMessage = decodeMessage(words);
    cout<<decodedMessage.substr(1)<<endl;
    return 0;
}
