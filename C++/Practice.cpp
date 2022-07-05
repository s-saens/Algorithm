#include <iostream>
#include <queue>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
using namespace std;

int Y, X;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visited[10][10][10][10] = {false};

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NONE
};

struct Point
{
    int x, y;
    bool operator==(const Point& p)
    {
        return (p.x == x) && (p.y == y);
    }
};

struct Snapshot
{
    Point redPoint, bluePoint;
    Direction last_dir = NONE;
    int move_cnt = 0;
    bool redCompleted = false;
    bool blueCompleted = false;

    bool operator==(const Snapshot& s)
    {
        return (redPoint == s.redPoint) && (bluePoint == s.bluePoint);
    }
};

char** blocks;
Point goal;

Snapshot NewSnapshot(Snapshot snapshot, Direction d)
{
    Snapshot s = snapshot;
    // Red
    while(blocks[s.redPoint.y][s.redPoint.x] == '.' && !(s.bluePoint == s.redPoint))
    {
        s.redPoint.x += dx[d]; s.redPoint.y += dy[d];
    }
    s.redCompleted = (s.redPoint == goal);
    if(!s.redCompleted)
    {
        s.redPoint.x -= dx[d]; s.redPoint.y -= dy[d];
    }

    // Blue
    while(blocks[s.bluePoint.y][s.bluePoint.x] == '.' && !(s.bluePoint == s.redPoint))
    {
        s.bluePoint.x += dx[d]; s.bluePoint.y += dy[d];
    }
    s.blueCompleted = (s.bluePoint == goal);
    if(!s.blueCompleted)
    {
        s.bluePoint.x -= dx[d]; s.bluePoint.y -= dy[d];
    }
    else return s;

    // Red
    while(blocks[s.redPoint.y][s.redPoint.x] == '.' && !(s.bluePoint == s.redPoint))
    {
        s.redPoint.x += dx[d]; s.redPoint.y += dy[d];
    }
    s.redCompleted = (s.redPoint == goal);
    if(!s.redCompleted)
    {
        s.redPoint.x -= dx[d]; s.redPoint.y -= dy[d];
    }

    s.move_cnt++;
    s.last_dir = d;

    return s;
}

void Pr(Snapshot s)
{
    FOR(i, 0, s.move_cnt) cout << ' ';
    cout << '(' << s.redPoint.x << ',' << s.redPoint.y << ")(" << s.bluePoint.x << ',' << s.bluePoint.y << ")\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Y >> X;
    blocks = new char*[Y];
    FOR(y, 0, Y) blocks[y] = new char[X];

    Snapshot firstSnapshot;

    FOR(y, 0, Y) FOR(x, 0, X)
    {
        char input; cin >> input;
        blocks[y][x] = input == 'R' || input == 'B' ? '.' : input;

        Point p = (struct Point){x, y};
        if(input == 'R') firstSnapshot.redPoint = p;
        else if(input == 'B') firstSnapshot.bluePoint = p;
        else if(input == 'O') goal = p;
    }

    queue<Snapshot> q;
    q.push(firstSnapshot);
    while (!q.empty())
    {
        Snapshot f = q.front(); q.pop();
        visited[f.redPoint.x][f.redPoint.y][f.bluePoint.x][f.bluePoint.y] = true;
        Pr(f);

        FOR(i, 0, 4)
        {
            if((f.last_dir == LEFT && i == RIGHT)
            || (f.last_dir == RIGHT && i == LEFT)
            || (f.last_dir == DOWN && i == UP)
            || (f.last_dir == UP && i == DOWN) ) continue;
            Snapshot newSnapshot = NewSnapshot(f, (Direction)i);

            if(newSnapshot == f) continue;
            if(visited[newSnapshot.redPoint.x][newSnapshot.redPoint.y][newSnapshot.bluePoint.x][newSnapshot.bluePoint.y]) continue;
            if(newSnapshot.blueCompleted) continue;
            if(newSnapshot.redCompleted)
            {
                cout << newSnapshot.move_cnt;
                return 0;
            }
            q.push(newSnapshot);
        }
    }

    cout << -1;
    return 0;
}

/*
10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#...##.#
#.#.#.#..#
#...#.O#.#
##########
*/