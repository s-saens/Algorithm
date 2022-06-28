#include <iostream>
#include <algorithm>
#define FOR(i,s,e) for(int i=s;i<e;++i)
#define MIN -2147483648
using namespace std;

int cnt = 0;
int N;
bool** isWall;
int dX[3] = {1, 0, 1};
int dY[3] = {0, 1, 1};

/*
dir
0: →
1: ↓
2: ↘︎
*/
void DFS(int x, int y, int lastDir, int c)
{
    if (x == N-1 && y == N-1) { cnt++; return; }

    FOR(i, 0, 3)
    {
        int nx = x + dX[i];
        int ny = y + dY[i];
        if((lastDir * i == 0 && lastDir + i == 1)
        || (nx >= N)
        || (ny >= N)
        || (isWall[ny][nx])
        ) continue;

        if( i == 2 && (isWall[ny][x] || isWall[y][nx]) )
        {
            continue;
        }

        DFS(nx, ny, i, c+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    isWall = new bool*[N];
    FOR(i,0,N) isWall[i] = new bool[N];


    FOR(y, 0, N) FOR(x, 0, N) cin >> isWall[y][x];

    DFS(1, 0, 0, 0);

    cout << cnt;
}