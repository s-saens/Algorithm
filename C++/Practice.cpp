#include <iostream>
#define ll long long

using namespace std;

const int dpSize = 1001;
ll dp[dpSize];

void InitDP()
{
    for(int i=0 ; i<dpSize ; ++i)
    {
        dp[i] = -1;
    }
    dp[1] = 1;
    dp[2] = 3;
}

ll Tile(int n)
{
    if(dp[n] > -1)
    {
        return dp[n];
    }

    ll answer = Tile(n-1) + 2 * Tile(n-2);
    dp[n] = answer % 10007;
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    InitDP();

    int N; cin >> N;

    cout << Tile(N);

    return 0;
}