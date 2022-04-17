#include <iostream>
#include <queue>

#define ll long long int
using namespace std;

char dX[4] = {-1, 1, 0, 0};
char dY[4] = {0, 0, -1, 1};

struct Point
{
    short x, y, d;
    Point() {}
    Point(int _x, int _y, int _d)
    {
        x = _x;
        y = _y;
        d = _d;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    cin >> Y >> X;

    bool p[Y][X];
    bool v[Y][X];

    for(int y=0 ; y<Y ; ++y)
    {
        for(int x=0 ; x<X ; ++x)
        {
            p[y][x] = false;
            v[y][x] = false;
        }
    }

    for (int y = 0; y < Y; ++y)
    {
        string input; cin >> input;
        for (int x = 0; x < X; ++x) p[y][x] = input[x] - '0';
    }

    queue<Point> q;
    q.push(Point(0,0,1));

    int d;

    while(!q.empty())
    {
        Point f = q.front(); q.pop();
        if(v[f.y][f.x]) continue;
        v[f.y][f.x] = true;
        d = f.d;

        if(f.x == X-1 && f.y == Y-1) break;

        for(int i=0 ; i<4 ; ++i)
        {
            int nX = f.x + dX[i];
            int nY = f.y + dY[i];

            if(nX < 0 || nX >= X || nY < 0 || nY >= Y) continue;


            if(!v[nY][nX] && p[nY][nX])
            {
                q.push(Point(nX, nY, f.d+1));
            }
        }
    }

    cout << d;

    return 0;
}