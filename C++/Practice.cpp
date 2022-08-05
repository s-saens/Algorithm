#include <iostream>
#include <queue>
#define FOR(i,s,e)for(int i=s;i<e;++i)
#define ll
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct Point
{
    int x, y;
    Point(int _x, int _y)
    {
        x = _x; y = _y;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Y, X;
    cin >> Y >> X;

    bool cheese[Y][X];
    bool visited[Y][X];

    int remainCheese = Y*X;
    int lastRemianCheese = -1;

    FOR(y,0,Y) FOR(x,0,X)
    {
        cin >> cheese[y][x];
        remainCheese -= !cheese[y][x];
        visited[y][x] = false;
    }
    
    queue<Point> q;
    q.push(Point(0,0));
    visited[0][0] = true;

    queue<Point> q2;

    int d = 0;

    while(remainCheese > 0)
    {
        while(!q.empty())
        {
            Point p = q.front(); q.pop();


            FOR(i, 0, 4)
            {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];

                if(nx < 0 || ny < 0 || nx >= X || ny >= Y || visited[ny][nx]) continue;
                visited[ny][nx] = true;

                if(cheese[ny][nx]) q2.push(Point(nx, ny));
                else q.push(Point(nx, ny));

                cheese[ny][nx] = 0;
            }
        }

        lastRemianCheese = remainCheese;
        d++;

        while(!q2.empty())
        {
            Point p2 = q2.front(); q2.pop();
            remainCheese--;
            q.push(p2);
        }
    }

    cout << d << '\n' << lastRemianCheese;


    return 0;
}