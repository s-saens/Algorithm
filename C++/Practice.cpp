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
    FOR(y,0,Y)
    {
        blocks[y] = new int[X];
        string input; cin >> input;
        FOR(x,0,X)
        {
            blocks[y][x] = input[x] - '0';
            if(blocks[y][x] == 0) blQ.push(Point(x, y));
        }
    }

    while(!blQ.empty()) // 0인 부분 빼기
    {
        Point blp = blQ.front(); blQ.pop();
        if(blocks[blp.y][blp.x] < 0) continue;

        queue<Point> q;
        queue<Point> q2;
        q.push(blp);

        int cnt0 = 0;

        while(!q.empty())
        {
            Point p = q.front(); q.pop();
            blocks[p.y][p.x] = -1;
            cnt0++;
            
            FOR(i, 0, 4)
            {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if(nx<0 || ny<0 || nx>=X || ny>=Y) continue;
                Point np = Point(nx, ny);

                if(blocks[ny][nx] > 0)
                {
                    blocks[ny][nx] *= -1;
                    q2.push(np);
                }
                else if(blocks[ny][nx] == 0)
                {
                    blocks[ny][nx] = -1;
                    q.push(np);
                }
            }
        }

        while(!q2.empty())
        {
            Point p2 = q2.front(); q2.pop();
            blocks[p2.y][p2.x] *= -1;
            blocks[p2.y][p2.x] += cnt0;
        }
    }

    FOR(y,0,Y)
    {
        FOR(x,0,X)
        {
            int bc = blocks[y][x] % 10;
            if(bc < 0) bc = 0;
            cout << bc;
        }
        cout << '\n';
    }

    return 0;
}