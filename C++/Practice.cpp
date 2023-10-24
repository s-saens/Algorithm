#include <iostream>
#define FOR(i,e) for(int i=0 ; i<e; ++i)

using namespace std;

int Y, X;
int h[501][501];
int dp[501][501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int dfs(int x, int y)
{
    if(x == X-1 && y == Y-1)
    {
        return 1;
    }
    if(dp[y][x] > -1) return dp[y][x];

    dp[y][x] = 0;

    FOR(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= X || ny < 0 || ny <= Y && h[ny][nx] >= h[y][x]) continue;

        dp[y][x] = dp[y][x] + dfs(nx, ny);
    }

    return dp[y][x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Y >> X;

    FOR(y, Y) FOR(x, X)
    {
        cin >> h[y][x];
        dp[y][x] = -1;
    }

    cout << dfs(0, 0);
}