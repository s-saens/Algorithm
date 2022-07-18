#include <iostream>
#include <cmath>
#include <vector>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
using namespace std;

bool** island;
bool** visited;

int X=1, Y=1;
int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[8] = {-1, 1, 0, 0, 1, -1, -1, 1};

void DFS(int x, int y)
{
    visited[y][x] = 1;
    FOR(i, 0, 8)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= X || ny >= Y || !island[ny][nx] || visited[ny][nx]) continue;
        DFS(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> X >> Y;
    vector<int> answers;

    while(X != 0 && Y != 0)
    {
        int cnt = 0;
        island = new bool*[Y];
        visited = new bool*[Y];
        FOR(y, 0, Y)
        {
            island[y] = new bool[X];
            visited[y] = new bool[X];
            FOR(x, 0, X) visited[y][x] = 0;
        }

        FOR(y, 0, Y) FOR(x, 0, X) cin >> island[y][x];

        FOR(y, 0, Y) FOR(x, 0, X)
        {
            if(island[y][x] && !visited[y][x])
            {
                DFS(x, y);
                cnt++;
            }
        }

        answers.push_back(cnt);

        cin >> X >> Y;
    }

    FOR(i, 0, answers.size()) cout << answers[i] << '\n';

    return 0;
}