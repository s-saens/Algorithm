#include <iostream>
#include <algorithm>
#define FOR(i, s, e) for(int i=s ; i<e; ++i)

using namespace std;

int N;

int arr[101][101];
bool flooded[101][101];
bool visited[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void init()
{
    FOR(i, 0, N) FOR(j, 0, N)
    {
        flooded[i][j] = false;
        visited[i][j] = false;
    }
}

void dfs(int y, int x)
{
    visited[y][x] = true;

    FOR(i, 0, 4)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if(visited[ny][nx]) continue;
        if(flooded[ny][nx]) continue;

        dfs(ny, nx);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int maxH = 0, minH = 101;

    FOR(y, 0, N) FOR(x, 0, N)
    {
        cin >> arr[y][x];
        int h = arr[y][x];
        maxH = max(maxH, h);
        minH = min(minH, h);
    }

    int answer = 0;

    FOR(h, minH-1, maxH)
    {
        int cnt = 0;
        init();

        // 일단 각각 물에 잠가
        FOR(y, 0, N) FOR(x, 0, N) if(arr[y][x] <= h) flooded[y][x] = true;

        FOR(y, 0, N) FOR(x, 0, N)
        {
            if(visited[y][x]) continue;
            if(flooded[y][x]) continue;

            dfs(y, x);
            cnt++;
        }

        answer = max(answer, cnt);
    }

    cout << answer;

    return 0;
}