#include <iostream>
#include <queue>
#define FOR(i,s,e) for(int i=s;i<e;++i)
#define MAX 100002
using namespace std;

struct Snapshot
{
    int x, t=0;
    Snapshot(int _x, int _t)
    {
        x = _x; t = _t;
    }
};

int N, K;
bool visited[MAX] = { 0 };
short dx[3] = {1, -1, 2};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    if(N >= K)
    {
        cout << N-K << '\n' << 1;
        return 0;
    }

    int minTime = MAX;
    int answerCnt = 0;

    queue<Snapshot> q;
    q.push(Snapshot(N, 0));

    while(!q.empty())
    {
        Snapshot s = q.front(); q.pop();
        if(answerCnt > 0 && minTime <= s.t) break;
        visited[s.x] = 1;

        FOR(i, 0, 3)
        {
            int nx = i<2 ? s.x + dx[i] : s.x * 2;
            if(nx == K)
            {
                answerCnt++;
                minTime = s.t + 1;
                continue;
            }

            if(nx < 0 || nx >= MAX || visited[nx]) continue;

            q.push(Snapshot(nx, s.t+1));
        }
    }

    cout << minTime << '\n' << answerCnt;

    return 0;
}