#include <iostream>
#include <queue>
#define FOR(i, e) for (int i=0; i<e; ++i)
using namespace std;

struct Point
{
    int x, y, turn=0, lastDir=-1;
    Point(int _x, int _y, int _t, int _l)
    {
        x = _x; y = _y, turn = _t;
        lastDir = _l;
    }
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int X, Y;
string* board;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> X >> Y;
    board = new string[Y];
    int turnCnt[Y][X];

    int startX, startY, endX, endY;
    bool started = 0;

    FOR(y,Y)
    {
        cin >> board[y];
        FOR(x, X)
        {
            if(board[y][x] == 'C')
            {
                if(!started)
                {
                    startX = x;
                    startY = y;
                    started = 1;
                }
                else
                {
                    endX = x;
                    endY = y;
                }
            }
            turnCnt[y][x] = 98754321;
        }
    }

    queue<Point> q;
    q.push(Point(startX, startY, 0, -1));
    board[startY][startX] = '*';

    while(!q.empty())
    {
        Point p = q.front(); q.pop();

        FOR(i, 4)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int nt = p.turn;
            Point np = Point(nx, ny, nt, i);

            if (nx < 0 || ny < 0 || nx >= X || ny >= Y || board[ny][nx] == '*') continue;
            if(i != p.lastDir) np.turn++;

            if(turnCnt[ny][nx] >= np.turn)
            {
                turnCnt[ny][nx] = np.turn;
                q.push(np);
            }
        }
    }

    cout << turnCnt[endY][endX] - 1;




    return 0;
}