#include <iostream>
#include <algorithm>
#include <climits>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

struct input
{
    int num, ind;
};

int n, a[maxN], indBeg = INT_MAX, indEnd, aSort[maxN];
input arr[maxN];

bool cmp(input x, input y)
{
    return x.num < y.num;
}
void reverseArr(int beg, int en)
{
    for(int i = beg, j = en; i < j; i++, j--)
    {
        swap(a[i], a[j]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i].num;
        arr[i].ind = i;
    }

    sort(arr, arr + n, cmp);

    for(int i = 0; i < n; i++)
    {
        a[arr[i].ind] = i;
        aSort[arr[i].ind] = i;
    }

    for(int i = 0; i < n; i++)
    {
        if(a[i] != i)
        {
            indBeg = i;
            indEnd = a[i];
            break;
        }
    }

    if(indBeg == INT_MAX)
    {
        cout<<"yes"<<endl<<1<<" "<<1<<endl;
        return 0;
    }

    reverseArr(indBeg, indEnd);
    sort(aSort, aSort + n);

    for(int i = 0; i < n; i++)
    {
        if(a[i] != aSort[i])
        {
            cout<<"no"<<endl;
            return 0;
        }
    }

    cout<<"yes"<<endl<<indBeg + 1<<" "<<indEnd + 1<<endl;
    return 0;
}
