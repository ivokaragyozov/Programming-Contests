/**
Ivo Karagyozov
Esenen 2015 C2 swap
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 105, maxSteps = 1e6 + 5;

int n, a[maxN], steps[maxSteps], ind, steps2[maxSteps], ind2, indA;

void printA()
{
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void recursion(int k)
{
    if(a[k] != k + 2)
    {
        steps[ind++] = k + 1;
        swap(a[k], a[k + 1]);
        return;
    }

    recursion(k - 1);
    steps[ind++] = k + 1;
    swap(a[k], a[k + 1]);
}
bool isPos(int k)
{
    for(int i = k - 2; i >= 0; i--)
    {
        if(a[i] > k + 1) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(a[i] != i + 1)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[j] == i + 1)
                {
                    indA = j;
                    break;
                }
            }

            for(int j = indA; j >= i + 1; j--)
            {
                if(a[j - 1] != j + 1 || a[j] == j || (a[j - 1] == j + 1 && isPos(j)))
                {
                    steps[ind++] = j;
                    swap(a[j], a[j - 1]);
                }
                else
                {
                    ind2 = 0;
                    recursion(j - 1);
                }
            }
        }
    }

    cout<<ind<<endl;
    for(int i = 0; i < ind; i++)
    {
        cout<<steps[i]<<" "<<steps[i] + 1<<endl;
    }

    return 0;
}
