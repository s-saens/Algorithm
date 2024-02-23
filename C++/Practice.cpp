#include <string>
#include <vector>
#include <queue>
#define FOR(i,s,e) for(int i=s ; i<e ; ++i)

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool map[102][102];
bool visited[102][102];
bool isInRect[102][102];

void init()
{
    FOR(i, 0, 102) FOR(j, 0, 102)
    {
        map[i][j] = false;
        visited[i][j] = false;
        isInRect[i][j] = false;
    }
}

struct Point {int x, y, cnt;};

int solution(vector<vector<int>> rectangle, int sx, int sy, int ex, int ey)
{
    int answer = 0;
    
    // init map
    for(const auto& r : rectangle)
    {
        int x1 = r[0] * 2, y1 = r[1] * 2, x2 = r[2] * 2, y2 = r[3] * 2;
        
        FOR(y, y1, y2+1) FOR(x, x1, x2+1)
        {
            if(y == y1 || y == y2 || x == x1 || x == x2) map[y][x] = true;
            else isInRect[y][x] = true;
        }
        
    }
    
    sy *= 2; sx *= 2; ey *= 2; ex *= 2;
    
    queue<Point> q;
    q.push({sx, sy, 0});
    
    int cnt = 0;
    
    while(!q.empty())
    {
        Point p = q.front(); q.pop();
        visited[p.y][p.x] = true;
        
        FOR(i, 0, 4)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            
            if(nx < 1 || nx > 101 || ny <1 || ny > 101 || !map[ny][nx] || visited[ny][nx] || isInRect[ny][nx]) continue;
            if(ny == ey && nx == ex) return (p.cnt + 1) / 2;
            
            cnt = p.cnt + 1;
            q.push({nx, ny, p.cnt + 1});
        }
    }
    
    return cnt / 2;
}