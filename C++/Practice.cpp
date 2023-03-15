#include <iostream>
#include <algorithm>
#define FOR(i,s,e) for(int i=s ; i<e ; ++i)
#define MAX 1000
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int **blocks;

int find12(int x, int y, int lastDir, int turnCnt, int moveCnt)
{
    if(turnCnt == 0 && moveCnt == 2) return blocks[y][x];
    if(turnCnt == 2) return blocks[y][x];

    blocks[y][x] = 0;

    FOR(i, 0, 4)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx>=6 || nx<0 || ny>=6 || ny<0 || blocks[ny][nx] == 0) continue;

        int value = find12(nx, ny, i, (lastDir == -1 || lastDir == i) ? turnCnt : turnCnt+1, moveCnt+1);
        if(value != 0) return value;
    }
    return 0;
}

bool check()
{
    int floor[6];

    FOR(y, 0, 6)
    {
        floor[y] = 0;
        FOR(x, 0, 6) if(blocks[y][x] != 0) floor[y]++;
    }

    FOR(i, 0, 6) if(floor[i] == 3) return true;

    FOR(y, 0, 6)
    {
        floor[y] = 0;
        FOR(x, 0, 6) if (blocks[x][y] != 0) floor[y]++;
    }

    FOR(i, 0, 6) if(floor[i] == 3) return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    blocks = new int*[6];

    int fx = 0, fy = 0;
    int maxX = -1, minX = MAX, maxY = -1, minY = MAX;

    FOR(y,0,6)
    {
        blocks[y] = new int[6];
        FOR(x,0,6)
        {
            int n; cin >> n;
            blocks[y][x] = n;
            if(n > 0)
            {
                maxX = max(maxX, x); minX = min(minX, x);
                maxY = max(maxY, y); minY = min(minY, y);
                if(n == 1)
                {
                    fx = x;
                    fy = y;
                }
            }
        }
    }

    int w = maxX - minX + 1;
    int h = maxY - minY + 1;

    if(w * h == 10 && check()) // 5 x 2
    {
        cout << find12(fx, fy, -1, 0, 0);
        return 0;
    }

    if(w * h != 12)
    {
        cout << 0;
        return 0;
    }

    cout << find12(fx, fy, -1, 0, 0);

    return 0;
}