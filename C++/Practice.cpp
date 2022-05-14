#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Point
{
    int x;
    int cnt;
    Point(int _x, int _cnt)
    {
        x = _x;
        cnt = _cnt;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nexts[100];
    memset(nexts, -1, sizeof(nexts));

    int N, M;
    cin >> N >> M;

    for(int i=0 ; i<N+M ; ++i)
    {
        int f, t;
        cin >> f >> t;

        nexts[f-1] = t-1;
    }

    queue<Point> q;
    q.push(Point(0, 0));

    while(!q.empty())
    {
        Point p = q.front(); q.pop();
        int x = p.x;
        int cnt = p.cnt;

        if(x == 99)
        {
            cout << cnt;
            return 0;
        }

        if(nexts[x] > -1) q.push(Point(nexts[x], cnt + 1));
        
        bool normal = false;
        for(int i=6 ; i>0 ; --i)
        {
            int nx = x + i;

            if (nx == 99)
            {
                cout << cnt + 1;
                return 0;
            }

            if(nx > 99) continue;
            
            if(nexts[nx] > -1)
            {
                q.push(Point(nexts[nx], cnt + 1));
            }
            else if(!normal)
            {
                normal = true;
                q.push(Point(nx, cnt + 1));
            }
        }
    }

    return 0;
}