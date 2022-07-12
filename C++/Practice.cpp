#include <iostream>
#include <queue>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

struct Snapshot
{
    int x, y;
    int dist = 1;
    bool destroy = false;

    Snapshot(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Y, X; cin >> Y >> X;

    if(Y == 1 && X == 1)
    {
        cout << 1;
        return 0;
    }

    bool blocked[Y][X];
    bool visited[Y][X];
    bool visited_crashed[Y][X];

    FOR(y, 0, Y)
    {
        string input;
        cin >> input;
        FOR(x, 0, X)
        {
            blocked[y][x] = input[x]-'0';
            visited[y][x] = false;
            visited_crashed[y][x] = false;
        }
    }

    queue<Snapshot> q;
    q.push(Snapshot(0, 0));

    while(!q.empty())
    {
        Snapshot f = q.front(); q.pop();
        if(!f.destroy) visited[f.y][f.x] = true;
        if(f.destroy) visited_crashed[f.y][f.x] = true;

        FOR(i, 0, 4)
        {
            int nx = f.x + dx[i];
            int ny = f.y + dy[i];

            if(ny < 0 || ny >= Y || nx < 0 || nx >= X) continue;

            if(nx == X-1 && ny == Y-1)
            {
                cout << f.dist + 1;
                return 0;
            }

            
            if(!f.destroy && visited[ny][nx]) continue;
            if(f.destroy && visited_crashed[ny][nx]) continue;

            Snapshot snapshot = Snapshot(nx, ny);
            snapshot.destroy = f.destroy;

            if(blocked[ny][nx])
            {
                snapshot.destroy = true;
                if(f.destroy) continue;
            }
            snapshot.dist = f.dist + 1;

            if(!snapshot.destroy) visited[ny][nx] = true;
            if(snapshot.destroy) visited_crashed[ny][nx] = true;

            q.push(snapshot);
        }
    }

    cout << -1;

    return 0;
}