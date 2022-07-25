#include <iostream>
#include <queue>
#define FOR(i,s,e) for(int i=s;i<e;++i)
using namespace std;

short dx[4] = {0, 0, -1, 1};
short dy[4] = {-1, 1, 0, 0};

struct Point
{
    int x, y, d = 0;
    bool brokeAlready = false;
    Point(int _x, int _y){x = _x;y = _y;}
    Point(int _x, int _y, int _d, bool br)
    {
        x = _x; y = _y; d = _d;  brokeAlready = br;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Y, X;
    cin >> Y >> X;

    int startX, startY, endX, endY;
    cin >> startY >> startX >> endY >> endX;
    startX--; startY--; endX--; endY--;

    bool maze[Y][X];
    bool visited[Y][X][2];
    FOR(y, 0, Y) FOR(x, 0, X)
    {
        visited[y][x][0] = 0;
        visited[y][x][1] = 0;
        cin >> maze[y][x];
    }

    queue<Point> q;
    q.push(Point(startX, startY));
    visited[startY][startX][0] = true;
    if(startY == endY && startX == endX)
    {
        cout << 0;
        return 0;
    }

    while(!q.empty())
    {
        Point p = q.front(); q.pop();

        FOR(i, 0, 4)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(nx<0||ny<0||nx>=X||ny>=Y||visited[ny][nx][p.brokeAlready]) continue;
            if(ny == endY && nx == endX)
            {
                cout << p.d + 1;
                return 0;
            }
            if(maze[ny][nx] && p.brokeAlready) continue;
            visited[ny][nx][p.brokeAlready] = true;
            bool br = p.brokeAlready;
            if(maze[ny][nx]) br = true;
            q.push(Point(nx, ny, p.d+1, br));
        }
    }

    cout << -1;

    return 0;
}