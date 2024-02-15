#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, e) for(int i=0 ; i<e ; ++i)

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int getDirection(char c)
{
    if(c == 'N') return 0;
    if(c == 'E') return 1;
    if(c == 'S') return 2;
    if(c == 'W') return 3;
    return -1;
}

char directions[4] = {'N', 'E', 'S', 'W'};

struct Element
{
    int x, y, d;
};

int main()
{
    int Y=1, X=1;
    unsigned long long moves=1;

    while(Y > 0 && X > 0)
    {
        cin >> Y >> X >> moves;

        char map[Y][X];
        short visited[Y][X][4];
        FOR(y, Y) FOR(x, X) FOR(i, 4) visited[y][x][i] = -1;

        int sx = 0, sy = 0, dir = 0; // 0, 1, 2, 3 : N, E, S, W
        FOR(y, Y) FOR(x, X)
        {
            cin >> map[y][x];

            int d = getDirection(map[y][x]);
            if(d >= 0)
            {
                sx = x; sy = y; dir = d;
            }
        }

        vector<Element> dp;
        while(moves > 0)
        {
            visited[sy][sx][dir]++;
            if(visited[sy][sx][dir] == 1)
            {
                dp.push_back({sx, sy, dir});
            }
            else if(visited[sy][sx][dir] == 2)
            {
                moves %= dp.size();
                sy = dp[moves].y;
                sx = dp[moves].x;
                dir = dp[moves].d;
                break;
            }

            for(int i=0 ; i<4 ; ++i)
            {
                int nextDir = (i + dir) % 4;
                int nx = sx + dx[nextDir];
                int ny = sy + dy[nextDir];

                if(nx < 0 || ny < 0 || nx >= X || ny >= Y || map[ny][nx] == '#') continue;

                dir = nextDir;
                break;
            }

            sx += dx[dir];
            sy += dy[dir];

            moves--;
        }

        if(Y > 0 && X > 0) cout << sy + 1 << ' ' << sx + 1 << ' ' << directions[dir] << '\n';
        else break;
    }
    
    return 0;
}