#include <iostream>
#include <queue>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
using namespace std;

struct Point
{
    int x, y;
    Point(int _x, int _y) { x = _x; y = _y; }
};

int X, Y, L;
char** MAP;
bool** visited;
short dx[4] = {0, 0, -1, 1};
short dy[4] = {-1, 1, 0, 0};

bool bfs(int x, int y)
{
    int swans = 0;
    queue<Point> q, xQ;
    q.push(Point(x, y));
    visited[y][x] = 1;

    while(!q.empty())
    {
        Point p = q.front(); q.pop();

        FOR(i, 0, 4)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(nx<0 || ny<0 || nx>=X || ny>=Y || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            switch (MAP[ny][nx])
            {
                case 'L': swans++; if(swans == L) return true;
                case '.': q.push(Point(nx, ny)); break;
                case 'X': MAP[ny][nx] = '.'; break;
            }
        }
    }
    return false;
}

void InitVisited()
{
    FOR(y, 0, Y) FOR(x, 0, X) visited[y][x] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Y >> X;

    MAP = new char*[Y];
    visited = new bool*[Y];
    FOR(y, 0, Y)
    {
        MAP[y] = new char[X];
        visited[y] = new bool[Y];
        string input; cin >> input;
        FOR(x, 0, X)
        {
            MAP[y][x] = input[x];
            if(input[x] == 'L') L++;
        }
    }

    int days = 0;
    while(true)
    {
        InitVisited();

        FOR(y, 0, Y) FOR(x, 0, X) if(!visited[y][x] && MAP[y][x] == '.' && bfs(x, y))
        {
            cout << days;
            return 0;
        }
        days++;
    }

    return 0;
}