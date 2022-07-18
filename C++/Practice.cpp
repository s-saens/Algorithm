#include <iostream>
#include <queue>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
using namespace std;

struct P
{
    int x, y, cnt=0;
    P() {}
    P(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    P(int _x, int _y, int _c)
    {
        x = _x;
        y = _y;
        cnt = _c;
    }
    P operator+ (const P& p)
    {
        return P(p.x + x, p.y + y, cnt+1);
    }
    P operator- (const P& p)
    {
        return P(x - p.x, y - p.y, cnt);
    }
    bool operator== (const P& p)
    {
        return (p.x == x) && (p.y == y);
    }
};

P dif[8] = {P(-2, 1), P(-1, 2), P(1, 2), P(2, 1), P(2, -1), P(1, -2), P(-1, -2), P(-2, -1)};
bool** visited;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    int answers[T];

    FOR(t, 0, T)
    {
        int minimumCnt = 0;
        bool found = 0;
        int I; cin >> I;
        visited = new bool*[I];
        FOR(i, 0, I)
        {
            visited[i] = new bool[I];
            FOR(j, 0, I) visited[i][j] = 0;
        }

        P start, end;
        cin >> start.x >> start.y >> end.x >> end.y;

        queue<P> q;
        q.push(start);
        while(!q.empty())
        {
            P f = q.front(); q.pop();
            visited[f.y][f.x] = 1;

            FOR(i, 0, 8)
            {
                P np = f + dif[i];
                if(np.x < 0 || np.y < 0 || np.x >= I || np.y >= I) continue;
                if(visited[np.y][np.x]) continue;

                if(np == end)
                {
                    found = 1;
                    minimumCnt = np.cnt;
                    queue<P> emptyQ;
                    q = emptyQ;
                    break;
                }

                visited[np.y][np.x] = true;
                q.push(np);
            }
            if(found) break;
        }

        answers[t] = minimumCnt;
    }

    FOR(t, 0, T) cout << answers[t] << '\n';

    return 0;
}