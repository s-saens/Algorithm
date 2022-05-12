#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#define ll long long int
#define FOR(i, s, e) for (int i = s; i < e; ++i)

using namespace std;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

struct Vector2
{
    int x, y, t;
    Vector2() {}
    Vector2(int _x, int _y, int _t)
    {
        x = _x;
        y = _y;
        t = _t;
    }
};

struct CompareVector2
{
    bool operator()(Vector2 &v1, Vector2 &v2)
    {
        if(v1.t > v2.t) return true;
        else if(v1.t < v2.t) return false;

        if (v1.y > v2.y) return true;
        else if(v1.y < v2.y) return false;

        if(v1.x > v2.x) return true;
        else if(v1.x < v2.x) return false;
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int p[N][N];
    int passFlag[N][N]; // passFlag < 2 - (nowSize + eatenCnt)

    Vector2 start;
    FOR(y, 0, N) FOR(x, 0, N)
    {
        passFlag[y][x] = 0;
        cin >> p[y][x];
        if(p[y][x] == 9) start = Vector2(x, y, 0);
    }

    priority_queue<Vector2, vector<Vector2>, CompareVector2> q;
    q.push(start);

    passFlag[start.y][start.x] = -1;
    p[start.y][start.x] = 0;

    int nowSize = 2;
    int eatenCnt = 0;
    int totalEatenCnt = 0;

    int time = 0;

    while(true)
    {
        priority_queue<Vector2, vector<Vector2>, CompareVector2> fishes;

        while(!q.empty())
        {
            Vector2 now = q.top(); q.pop();
            int x = now.x;
            int y = now.y;

            FOR(i, 0, 4)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= N || ny < 0 || ny >= N || p[ny][nx] > nowSize) continue;
                if(passFlag[ny][nx] < 2 - (nowSize + totalEatenCnt)) continue;

                passFlag[ny][nx] = 1 - (nowSize + totalEatenCnt);

                if(p[ny][nx] == 0 || p[ny][nx] == nowSize) // 지나가기!
                {
                    if(fishes.empty()) q.push(Vector2(nx, ny, now.t + 1));
                }
                else if(p[ny][nx] < nowSize) // 잡아먹기 후보 추가
                {
                    fishes.push(Vector2(nx, ny, now.t + 1));
                }
            }
        }

        if(!fishes.empty())
        {
            Vector2 fish = fishes.top();
            q.push(fish);

            eatenCnt++;
            totalEatenCnt++;
            if (eatenCnt >= nowSize) // Size 갱신
            {
                eatenCnt = 0;
                nowSize++;
            }

            passFlag[fish.y][fish.x]--;
            p[fish.y][fish.x] = 0;

            time = fish.t;
        }
        else break;
    }

    cout << time;

    return 0;
}