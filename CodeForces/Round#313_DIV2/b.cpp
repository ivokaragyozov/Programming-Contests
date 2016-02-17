#include <iostream>
#define endl '\n'
using namespace std;

bool rotation1, rotation2, rotation3, rotation4, rotation5, rotation6, rotation7, rotation8;
int a1, b1, a2, b2, a3, b3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a1>>b1>>a2>>b2>>a3>>b3;

    rotation1 = (a2+a3 <= a1 && b1 >= max(b2, b3));
    rotation2 = (b2+b3 <= a1 && b1 >= max(a2, a3));
    rotation3 = (a2+a3 <= b1 && a1 >= max(b2, b3));
    rotation4 = (b2+b3 <= b1 && a1 >= max(a2, a3));
    rotation5 = (a2+b3 <= a1 && b1 >= max(b2, a3));
    rotation6 = (b2+a3 <= a1 && b1 >= max(a2, b3));
    rotation7 = (a2+b3 <= b1 && a1 >= max(b2, a3));
    rotation8 = (b2+a3 <= b1 && a1 >= max(a2, b3));

    if(rotation1 || rotation2 || rotation3 || rotation4 || rotation5 || rotation6 || rotation7 || rotation8) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
