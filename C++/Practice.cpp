#include <iostream>
#include <queue>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
using namespace std;

struct Point
{
    int x, y;
    Point(int _x, int _y) { x = _x; y = _y; }
};

int N, L, R;
int** populations;
bool** visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool canMove(int x, int y, int nx, int ny)
{
    if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx]) return false;
    
    int dif = abs(populations[ny][nx] - populations[y][x]);
    if(L <= dif && dif <= R) return true;
    return false;
}

bool bfs(int x, int y)
{
    visited[y][x] = 1;
    int sum = populations[y][x];
    int cnt = 1;
    queue<Point> q, tempQ;
    q.push(Point(x, y));

    while(!q.empty())
    {
        Point p = q.front(); q.pop();
        tempQ.push(p);

        FOR(i, 0, 4)
        {
            int nx = p.x + dx[i], ny = p.y + dy[i];

            if(!canMove(p.x, p.y, nx, ny)) continue;

            visited[ny][nx] = true;
            sum += populations[ny][nx];
            cnt++;
            q.push(Point(nx, ny));
        }
    }

    if(tempQ.size() == 1) return false;

    sum /= cnt;

    while(!tempQ.empty())
    {
        Point p = tempQ.front(); tempQ.pop();
        populations[p.y][p.x] = sum;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;

    populations = new int*[N];
    visited = new bool*[N];
    FOR(i, 0, N)
    {
        populations[i] = new int[N];
        visited[i] = new bool[N];
        FOR(j, 0, N)
        {
            cin >> populations[i][j];
            visited[i][j] = 0;
        }
    }

    int cnt = 0;
    bool found = true;
    while(found)
    {
        found = false;

        FOR(y, 0, N) FOR(x, 0, N) if(!visited[y][x] && bfs(x, y)) found = true;

        if(found)
        {
            FOR(y, 0, N) FOR(x, 0, N) visited[y][x] = 0;
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}