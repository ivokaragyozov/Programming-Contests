#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

long long t, health, armor, dp[2005][2005][4];

long long solve(long long a, long long b, long long c)
{
    if(a <= 0 || b <= 0) return -1;
    if(dp[a][b][c] != -1) return dp[a][b][c];

    int healthAir = a+3, healthWater = a-5, healthFire = a-20, armorAir = b+2, armorWater = b-10, armorFire = b+5;

    if(c == 1) dp[a][b][c] = max(solve(healthAir, armorAir, 2), solve(healthWater, armorWater, 3));
    else if(c == 2) dp[a][b][c] = max(solve(healthFire, armorFire, 1), solve(healthWater, armorWater, 3));
    else dp[a][b][c] = max(solve(healthFire, armorFire, 1), solve(healthAir, armorAir, 2));
    dp[a][b][c]++;

    return dp[a][b][c];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin>>t;
    for(int cs = 0; cs < t; cs++)
    {
        cin>>health>>armor;
        cout<<max(solve(health, armor, 1), max(solve(health, armor, 2), solve(health, armor, 3)))<<endl;
    }

    return 0;
}
