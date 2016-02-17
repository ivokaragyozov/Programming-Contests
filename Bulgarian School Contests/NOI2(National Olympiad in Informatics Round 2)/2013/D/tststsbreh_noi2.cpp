/**
Ivo Karagyozov
NOI2 2013 D3 tststsbreh
*/
#include<iostream>
using namespace std;
int main()
{
    string t;
    int n,maxbrg=0,maxbrs=0,brs=0,brg=0,br1=0,br2=0;
    cin>>n;
    for(int i=0;i<n;i++){
        getline(cin,t,'.');
        for(int j=0;j<t.size();j++){
            if(!(t[j]=='a'||t[j]=='e'||t[j]=='i'||t[j]=='o'||t[j]=='u'||t[j]=='y')&&isalpha(t[j])){
                brs++;
            }
            else {
                if(brs>maxbrs){
                    maxbrs=brs;
                }
                brs=0;
            }
            if(j==t.size()-1){
                if(brs>maxbrs){
                    maxbrs=brs;
                }
            }
        }
        if(maxbrs>3)br1++;
        else br2++;
        brs=0;
        maxbrs=0;
    }
    cout<<br2<<" "<<br1<<endl;
    return 0;
}
