#include <iostream>
#include <queue>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
using namespace std;

struct Point
{
    int x, y, d=0, s=0;
    Point(int _x, int _y) { x = _x; y = _y; }
    Point(int _x, int _y, int _d) { x = _x; y = _y; d = _d; }
};

int X, Y, L;
char** MAP;
bool** visited;
short dx[4] = {0, 0, -1, 1};
short dy[4] = {-1, 1, 0, 0};

void InitVisited()
{
    FOR(y, 0, Y) FOR(x, 0, X) visited[y][x] = 0;
}

bool IsNextToIce(int x, int y)
{
    FOR(i, 0, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
        if(MAP[ny][nx] == 'X') return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Y >> X;

    MAP = new char*[Y];
    visited = new bool*[Y];

    Point lastlp = Point(0, 0);

    FOR(y, 0, Y)
    {
        MAP[y] = new char[X];
        visited[y] = new bool[Y];
        string input; cin >> input;
        FOR(x, 0, X)
        {
            MAP[y][x] = input[x];
            if(input[x] == 'L')
            {
                lastlp = Point(x, y);
                L++;
            }
        }
    }

    queue<Point> q, xQ, lQ, lxQ;
    // q 초기화
    FOR(y, 0, Y) FOR(x, 0, X)
    {
        if(MAP[y][x] == 'L' || MAP[y][x] == '.') if(IsNextToIce(x, y)) q.push(Point(x, y));
    }
    lQ.push(lastlp);
    MAP[lastlp.y][lastlp.x] = '_';

    int days = 0, swans = 1;

    while(!q.empty())
    {
        Point p = q.front(); q.pop();

        FOR(i, 0, 4)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(nx<0 || ny<0 || nx>=X || ny>=Y || visited[ny][nx]) continue;
            visited[ny][nx] = true;

            if(MAP[ny][nx] == 'X')
            {
                MAP[ny][nx] = '/';
                days = p.d+1;
                xQ.push(Point(nx, ny, p.d+1));
            }
        }
        

        if(q.empty())
        {
            while(!lQ.empty())
            {
                Point lp = lQ.front(); lQ.pop();
                
                FOR(i, 0, 4)
                {
                    int lnx = lp.x + dx[i];
                    int lny = lp.y + dy[i];
                    if(lnx<0 || lny<0 || lnx>=X || lny>=Y) continue;
                    if(MAP[lny][lnx] == 'O') continue;
                    if(MAP[lny][lnx] == 'X')
                    {
                        lxQ.push(Point(lnx, lny));
                        continue;
                    }
                    if(MAP[lny][lnx] == 'L') swans++;

                    MAP[lny][lnx] = 'O';
                    if(swans == L)
                    {
                        cout << days;
                        return 0;
                    }
                    lQ.push(Point(lnx, lny));
                }
            }


            while(!xQ.empty()) { q.push(xQ.front()); xQ.pop(); }
            while(!lxQ.empty()) { lQ.push(lxQ.front()); lxQ.pop(); }
        }
    }
    cout << days;

    return 0;
}