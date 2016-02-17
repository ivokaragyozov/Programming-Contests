/**
Ivo Karagyozov
Esenen 2010 C3 prettynum
*/
#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 5;

bool p;
int n, a[maxN], arr[maxN], number[maxN], arr2[maxN], cnt[maxN], index[maxN], index2[maxN], ind, ind2, currCnt = 1, maxSize, currSize;
string currNumber, ans;
vector<int> beg, en;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>a[0];
    for(int i = 1; i < n; i++)
    {
        cin>>a[i];

        if(a[i] == a[i - 1]) currCnt++;
        else
        {
            index[ind] = i - currCnt;
            number[ind] = a[i - 1];
            arr[ind++] = currCnt;
            currCnt = 1;
        }
    }
    index[ind] = n - currCnt;
    number[ind] = a[n - 1];
    arr[ind++] = currCnt;

    currCnt =  1;
    for(int i = 1; i < ind; i++)
    {
        if(arr[i] == arr[i - 1]) currCnt++;
        else
        {
            cnt[ind2] = arr[i - 1];
            arr2[ind2] = currCnt;
            index2[ind2] = index[i - arr2[ind2]];
            ind2++;
            currCnt = 1;
        }
    }
    cnt[ind2] = arr[ind - 1];
    arr2[ind2] = currCnt;
    index2[ind2] = index[ind - arr2[ind2]];
    ind2++;

    int val1, val2, val3, val4, val5, val6, b1, b2, b3, b4, b5, b6, e1, e2, e3, e4, e5, e6;
    for(int i = 0; i <= ind2 - 1; i++)
    {
        if(cnt[i - 1] >= cnt[i] && cnt[i + 1] >= cnt[i] && i != 0 && i != ind2 - 1)
        {
            if(a[index2[i] - 1] == 0) val1 = -1;
            else
            {
                val1 = 2 * cnt[i] + cnt[i] * arr2[i];
                b1 = index2[i] - cnt[i];
                e1 = index2[i + 1] + cnt[i] - 1;
            }
        }
        else val1 = -1;

        if(cnt[i - 1] >= cnt[i] && i != 0)
        {
            if(a[index2[i] - 1] == 0) val2 = -1;
            else
            {
                val2 = cnt[i] * arr2[i] + cnt[i];
                b2 = index2[i] - cnt[i];
                e2 = index2[i + 1] - 1;
            }
        }
        else val2 = -1;

        if(cnt[i + 1] >= cnt[i] && i < ind2 - 1)
        {
            if(a[index2[i]] == 0) val3 = -1;
            else
            {
                val3 = cnt[i] * arr2[i] + cnt[i];
                b3 = index2[i];
                e3 = index2[i + 1] + cnt[i] - 1;
            }
        }
        else val3 = -1;

        if(cnt[i - 1] < cnt[i] && i != 0)
        {
            if(a[index2[i - 1]] == 0) val4 = -1;
            else
            {
                val4 = 2 * cnt[i - 1];
                b4 = index2[i] - cnt[i - 1];
                e4 = index2[i] + cnt[i - 1] - 1;
            }
        }
        else val4 = -1;

        if(cnt[i + 1] < cnt[i] && i < ind2 - 1)
        {
            if(a[index2[i]] == 0) val5 = -1;
            else
            {
                val5 = 2 * cnt[i + 1];
                b5 = index2[i + 1] - cnt[i + 1];
                e5 = index2[i + 1] + cnt[i + 1] - 1;
            }
        }
        else val5 = -1;

        if(a[index2[i]] != 0)
        {
            val6 = cnt[i] * arr2[i];
            b6 = index2[i];
            if(i < ind2 - 1) e6 = index2[i + 1] - 1;
            else e6 = n - 1;
        }
        else val6 = -1;

        if(val1 > maxSize)
        {
            maxSize = val1;
            beg.erase(beg.begin(), beg.end());
            en.erase(en.begin(), en.end());
            beg.push_back(b1);
            en.push_back(e1);
        }
        else if(val1 == maxSize)
        {
            beg.push_back(b1);
            en.push_back(e1);
        }

        if(val2 > maxSize)
        {
            maxSize = val2;
            beg.erase(beg.begin(), beg.end());
            en.erase(en.begin(), en.end());
            beg.push_back(b2);
            en.push_back(e2);
        }
        else if(val2 == maxSize)
        {
            beg.push_back(b2);
            en.push_back(e2);
        }

        if(val3 > maxSize)
        {
            maxSize = val3;
            beg.erase(beg.begin(), beg.end());
            en.erase(en.begin(), en.end());
            beg.push_back(b3);
            en.push_back(e3);
        }
        else if(val3 == maxSize)
        {
            beg.push_back(b3);
            en.push_back(e3);
        }

        if(val4 > maxSize)
        {
            maxSize = val4;
            beg.erase(beg.begin(), beg.end());
            en.erase(en.begin(), en.end());
            beg.push_back(b4);
            en.push_back(e4);
        }
        else if(val4 == maxSize)
        {
            beg.push_back(b4);
            en.push_back(e4);
        }

        if(val5 > maxSize)
        {
            maxSize = val5;
            beg.erase(beg.begin(), beg.end());
            en.erase(en.begin(), en.end());
            beg.push_back(b5);
            en.push_back(e5);
        }
        else if(val5 == maxSize)
        {
            beg.push_back(b5);
            en.push_back(e5);
        }

        if(val6 > maxSize)
        {
            maxSize = val6;
            beg.erase(beg.begin(), beg.end());
            en.erase(en.begin(), en.end());
            beg.push_back(b6);
            en.push_back(e6);
        }
        else if(val6 == maxSize)
        {
            beg.push_back(b6);
            en.push_back(e6);
        }
    }

    if(ind == 1 && a[0] == 0)
    {
        cout<<0<<endl;
        return 0;
    }

    for(int i = 0; i < beg.size(); i++)
    {
        currNumber = "";

        for(int j = beg[i]; j <= en[i]; j++)
        {
            currNumber += (char)(a[j] + '0');
        }

        if(!p || currNumber > ans)
        {
            ans = currNumber;
            p = true;
        }
    }

    cout<<ans<<endl;
    return 0;
}
