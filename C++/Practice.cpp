#include <iostream>
#include <queue>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
using namespace std;

struct Point
{
    int x, y;
    Point(int _x, int _y) {x=_x; y=_y;}
};

short dx[4] = {0, 0, -1, 1};
short dy[4] = {-1, 1, 0, 0};

int X, Y;
int** blocks;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Y >> X;

    blocks = new int*[Y];
    queue<Point> blQ;
    int blockCnt = 0;
    FOR(y,0,Y)
    {
        blocks[y] = new int[X];
        string input; cin >> input;
        FOR(x,0,X)
        {
            blocks[y][x] = 0;
            if(input[x] == '1')
            {
                blockCnt++;
                blocks[y][x] = -blockCnt; // block들은 순차적으로 -1, -2로 저장됨.
                blQ.push(Point(x, y));
            }
        }
    }

    while(!blQ.empty())
    {
        Point bp = blQ.front(); blQ.pop();
        int cnt = 0;

        queue<Point> q;
        q.push(bp);

        while(!q.empty())
        {
            Point p = q.front(); q.pop();
            FOR(i, 0, 4)
            {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];

                if(nx<0 || ny<0 || nx>=X || ny>=Y
                || blocks[ny][nx] > 0
                || blocks[ny][nx] <= blocks[bp.y][bp.x]) continue;

                blocks[ny][nx] = blocks[bp.y][bp.x];
                q.push(Point(nx, ny));
                cnt++;
            }
        }
        blocks[bp.y][bp.x] = cnt;
    }

    FOR(y,0,Y)
    {
        FOR(x,0,X)
        {
            int bc = (blocks[y][x] + 1) % 10;
            if(bc < 0) bc = 0;
            cout << bc;
        }
        cout << '\n';
    }

    return 0;
}