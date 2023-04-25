#include <iostream>
#include <algorithm>
#include <queue>

#define FOR(i,s,e) for(int i=s ; i<e ; ++i)
using namespace std;

int Y, X;
int** blocks;
queue<int> q; // BFS 큐 - 1차원 위치 저장

int dx[4] = {0, 0, 1, -1}, dy[4] = {-1, 1, 0, 0};

int bfs()
{
    int vcnt = 0;

    while(!q.empty())
    {
        vcnt++;
        int pos1d = q.front(); q.pop();
        int x = pos1d % X; int y = pos1d / X;

        FOR(i, 0, 4)
        {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || nx >= X || ny < 0 || ny >= Y || blocks[ny][nx] != 0) continue;
            q.push(nx + X*ny);
            blocks[ny][nx] = -1; // 방문 표시
        }
    }

    return vcnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Y >> X;
    int size1d = X * Y;

    blocks = new int *[Y];
    FOR(y, 0, Y) blocks[y] = new int[X];

    int wallCnt = 3; // 세워야 할 벽 세 개를 미리 포함시키기
    vector<int> viruses; // 바이러스 위치 1차원으로 저장

    FOR(y, 0, Y) FOR(x, 0, X)
    {
        cin >> blocks[y][x];
        switch (blocks[y][x])
        {
            case 1: wallCnt++; break; // 벽
            case 2: viruses.push_back(x + X*y); break; // 바이러스
        }
    }

    int virusCnt = viruses.size();

    int minimumViruses = 65;

    // 벽 위치 조합. i, j, k는 1차원 좌표.
    FOR(i, 0, size1d)
    {
        int x1 = i % X; int y1 = i / X; // i를 2차원 좌표로 변환
        if(blocks[y1][x1] != 0) continue; // 빈공간 아니면 패스
        blocks[y1][x1] = 1; // 벽 1 세우기

        FOR(j, i+1, size1d)
        {
            int x2 = j % X; int y2 = j / X; // j를 2차원 좌표로 변환
            if(blocks[y2][x2] != 0) continue; // 빈공간 아니면 패스
            blocks[y2][x2] = 1; // 벽 2 세우기

            FOR(k, j+1, size1d)
            {
                int x3 = k % X; int y3 = k / X; // k를 2차원 좌표로 변환
                if(blocks[y3][x3] != 0) continue; // 빈공간 아니면 패스
                blocks[y3][x3] = 1; // 벽 3 세우기

                    // BFS
                    FOR(p, 0, virusCnt) q.push(viruses[p]); // 바이러스를 큐에 추가
                    minimumViruses = min(minimumViruses, bfs()); // BFS 수행
                    FOR(y, 0, Y) FOR(x, 0, X) if(blocks[y][x] < 0) blocks[y][x] = 0; // 방문표시 없애기

                blocks[y3][x3] = 0; // 벽 3 없애기
            }
            blocks[y2][x2] = 0; // 벽 2 없애기
        }
        blocks[y1][x1] = 0; // 벽 1 없애기
    }

    cout << size1d - minimumViruses - wallCnt;

    return 0;
}