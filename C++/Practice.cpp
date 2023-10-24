#include <iostream>
#include <algorithm>
#include <unordered_set>
#define FOR(i,e) for(int i=0 ; i<e; ++i)

using namespace std;

struct Point
{
    int x, y;
    Point(int _x, int _y)
    {
        x = _x; y = _y;
    }

    bool operator == (const Point& other) const
    {
        return x == other.x && y == other.y;
    }
};

struct PointHash
{
    size_t operator()(const Point& p) const
    {
        hash<string> hash_func;
        return hash_func(to_string(p.x) + "," + to_string(p.y));
    }
};

int Y, X;
int h[501][501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int cnt;

void dfs(int x, int y, unordered_set<Point, PointHash> visited)
{
    visited.insert(Point(x, y));

    int nowH = h[y][x];

    FOR(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
        if (h[ny][nx] >= nowH) continue;
        if (visited.find(Point(nx, ny)) != visited.end()) continue;
        
        if (nx == X-1 && ny == Y-1)
        {
            cnt++;
            continue;
        }

        dfs(nx, ny, visited);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Y >> X;

    FOR(y, Y) FOR(x, X) cin >> h[y][x];

    dfs(0, 0, unordered_set<Point, PointHash>());

    cout << cnt;
}