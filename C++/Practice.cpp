#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FOR(i, N) for(int i=0 ; i<N ; ++i)

#define ll long long int
using namespace std;

char dx[4] = {-1, 1, 0, 0};
char dy[4] = {0, 0, -1, 1};

int N;

struct Point
{
    int x, y;
    bool h, v;
    Point() {}
    Point(int _x, int _y, bool _h, bool _v)
    {
        x = _x ; y = _y ; h = _h ; v = _v;
    }
};

Point** points;

int BFS(int x, int y)
{
    queue<Point> q;
    q.push(points[y][x]);

    int cnt = 0;
    while(!q.empty())
    {
        Point f = q.front(); q.pop();

        if(points[f.y][f.x].v) continue;
        points[f.y][f.x].v = true;

        cnt++;

        FOR(i, 4)
        {
            int nx = f.x + dx[i];
            int ny = f.y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(!points[ny][nx].v && points[ny][nx].h) q.push(points[ny][nx]);
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    
    points = new Point*[N];
    FOR(y, N) points[y] = new Point[N];
    
    FOR(y, N)
    {
        string input;
        cin >> input;
        FOR(x, N) points[y][x] = Point(x, y, input[x]-'0', false);
    }

    vector<int> answers;

    FOR(y, N) FOR(x, N) if(!points[y][x].v && points[y][x].h) answers.push_back(BFS(x, y));

    sort(answers.begin(), answers.end());

    cout << answers.size() << "\n";
    FOR(i, answers.size()) cout << answers[i] << "\n";


    return 0;
}