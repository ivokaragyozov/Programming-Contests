#include <iostream>
#include <map>
#include <vector>
#define endl '\n'
using namespace std;

int n, len;
string currAddress, login, domain, newAddress, newLogin;
map<string, vector<string> > distinct;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>currAddress;

        len = currAddress.size();
        login = "";
        domain = "";

        int j;
        for(j = 0; j < len; j++)
        {
            if(currAddress[j] == '@') break;

            login += tolower(currAddress[j]);
        }
        j++;
        for(; j < len; j++)
        {
            domain += tolower(currAddress[j]);
        }

        if(domain == "bmail.com")
        {
            newLogin = "";

            for(int p = 0; p < login.size(); p++)
            {
                if(login[p] == '+') break;
                if(login[p] == '.') continue;

                newLogin += login[p];
            }

            login = newLogin;
        }

        newAddress = login + '@' + domain;

        distinct[newAddress].push_back(currAddress);
    }

    map<string, vector<string> >::iterator it;

    cout<<distinct.size()<<endl;

    for(it = distinct.begin(); it != distinct.end(); it++)
    {
        cout<<(*it).second.size()<<" ";
        for(int i = 0; i < (*it).second.size(); i++)
        {
            cout<<(*it).second[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
