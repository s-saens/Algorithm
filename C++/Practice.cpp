#include <iostream>
#include <algorithm>
#define FOR(i,e) for(int i=0 ; i<e; ++i)

using namespace std;

int N;
int bamboo[501][501];
int dp[501][501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int dfs(int x, int y)
{
    if(dp[y][x] > -1) return dp[y][x];

    dp[y][x] = 1;

    FOR(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || bamboo[ny][nx] <= bamboo[y][x]) continue;

        dp[y][x] = max(dp[y][x], dfs(nx, ny) + 1);
    }

    return dp[y][x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    FOR(y, N) FOR(x, N)
    {
        cin >> bamboo[y][x];
        dp[y][x] = -1;
    }
    
    int answer = 0;
    FOR(y, N)
    {
        FOR(x, N)
        {
            answer = max(answer, dfs(x, y));
        }
    }

    cout << answer;
}