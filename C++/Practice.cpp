#include <iostream>
#include <queue>
#include <cmath>
#define MAX 20000000
#define FOR(i,e) for(int i=0;i<e;++i)
using namespace std;

struct Snapshot
{
    int x=0, y=0, b=0;
    Snapshot() {};
    Snapshot(int _x, int _y, int _b)
    {
        x = _x, y = _y, b = _b;
    }
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    bool white[N][N];
    int visit[N][N];

    FOR(y,N)
    {
        string input; cin >> input;
        FOR(x, N)
        {
            white[y][x] = input[x] - '0';
            visit[y][x] = MAX;
        }
    }

    int answer = MAX;

    queue<Snapshot> q;
    q.push(Snapshot());
    visit[0][0] = 0;

    while(!q.empty())
    {
        Snapshot s = q.front(); q.pop();

        FOR(i, 4)
        {
            int nx = s.x + dx[i], ny = s.y + dy[i], nb = s.b + !white[ny][nx];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if(visit[ny][nx] > nb) visit[ny][nx] = nb;
            else continue;

            if(nx == N-1 && ny == N-1) break;

            q.push(Snapshot(nx, ny, nb));
        }
    }
    cout << visit[N-1][N-1];

    return 0;
}