#include <iostream>
#include <cmath>
#define FOR(i,N) for(int i=0 ; i<N ; ++i)

using namespace std;

int *s[2];
int *dp[3];
int N;

void Init()
{
    FOR(i, 2)
    {
        delete s[i];
        s[i] = new int[N];
    }

    FOR(i, 3)
    {
        delete dp[i];
        dp[i] = new int[N];
        FOR(j, N) dp[i][j] = -1;
    }
}

int F(int x, int y)
{
    if(x >= N) return 0;
    if(dp[y][x] > -1) return dp[y][x];

    if(y == 2) dp[y][x] = max(s[1][x] + F(x + 1, 1), s[0][x] + F(x + 1, 0));
    else if(y == 1) dp[y][x] = s[0][x] + F(x + 1, 0);
    else if(y == 0) dp[y][x] = s[1][x] + F(x + 1, 1);
    dp[y][x] = max(dp[y][x], F(x + 1, 2));

    return dp[y][x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    int a[T];
    FOR(t, T)
    {
        cin >> N;
        Init();
        
        FOR(y, 2) FOR(x, N) cin >> s[y][x];

        a[t] = F(0, 2);
    }

    FOR(t, T) cout << a[t] << "\n";

    return 0;
}