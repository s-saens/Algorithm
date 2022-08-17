#include <iostream>
#include <vector>
#include <cmath>
#define FOR(i, e) for(int i=0; i<e ; ++i)
#define ll long long int
using namespace std;

struct Point
{
    int x, y;
    Point() {}
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    bool operator==(Point& p)
    {
        return x == p.x && y == p.y;
    }
};

struct Area
{
    Point startPoint, endPoint;
    Area(Point sp, Point ep)
    {
        startPoint = sp;
        endPoint = ep;
    }
    bool operator >> (Area& p) // left(this) Contains right(p)
    {
        return  startPoint.x <= p.startPoint.x && p.endPoint.x <= endPoint.x
            &&  startPoint.y <= p.startPoint.y && p.endPoint.y <= endPoint.y;
    }
    bool operator >> (Point& p) // area contains point
    {
        return  startPoint.x <= p.x && p.x <= endPoint.x
            &&  startPoint.y <= p.y && p.y <= endPoint.y;
    }

    bool operator &= (Area& p) // left(this) and right(p) shares nothing
    {
        return  startPoint.x > p.endPoint.x || endPoint.x < p.startPoint.x
            ||  startPoint.y > p.endPoint.y || endPoint.y < p.startPoint.y;
    }
};

ll N, M, numbers[1024][1024], segtree[1024 * 1024 * 8];

ll SetSegtree(int index, Area nowArea)
{

    int
    x1 = nowArea.startPoint.x,
    y1 = nowArea.startPoint.y,
    x2 = nowArea.endPoint.x,
    y2 = nowArea.endPoint.y,
    lenX = x2 - x1,
    lenY = y2 - y1;

    if(nowArea.startPoint == nowArea.endPoint)
    {
        segtree[index] = numbers[y1][x1];
        return numbers[y1][x1];
    }

    int mx = (x1 + x2) / 2;
    int my = (y1 + y2) / 2;
    ll sum = 0;
    int nextIndex[4];
    FOR(i, 4) nextIndex[i] = index * 4 + (i + 1);
    sum += SetSegtree(nextIndex[0], Area(Point(x1, y1), Point(mx, my)));
    if(lenX > 0) sum += SetSegtree(nextIndex[1], Area(Point(mx+1, y1), Point(x2, my)));
    if(lenY > 0) sum += SetSegtree(nextIndex[2], Area(Point(x1, my+1), Point(mx, y2)));
    if(lenX > 0 && lenY > 0) sum += SetSegtree(nextIndex[3], Area(Point(mx+1, my+1), Point(x2, y2)));

    segtree[index] = sum;

    return sum;
}

ll FindSum(int index, Area nowArea, Area targetArea)
{
    if(targetArea &= nowArea) return 0;
    if(targetArea >> nowArea) return segtree[index];

    int 
    x1 = nowArea.startPoint.x,
    y1 = nowArea.startPoint.y,
    x2 = nowArea.endPoint.x,
    y2 = nowArea.endPoint.y,
    lenX = x2 - x1,
    lenY = y2 - y1;

    int mx = (x1 + x2) / 2;
    int my = (y1 + y2) / 2;
    ll sum = 0;
    int nextIndex[4];
    FOR(i, 4) nextIndex[i] = index * 4 + (i + 1);
    sum += FindSum(nextIndex[0], Area(Point(x1, y1), Point(mx, my)), targetArea);
    if(lenX > 0) sum += FindSum(nextIndex[1], Area(Point(mx+1, y1), Point(x2, my)), targetArea);
    if(lenY > 0) sum += FindSum(nextIndex[2], Area(Point(x1, my+1), Point(mx, y2)), targetArea);
    if(lenX > 0 && lenY > 0) sum += FindSum(nextIndex[3], Area(Point(mx+1, my+1), Point(x2, y2)), targetArea);

    return sum;
}

void Modify(int index, Area nowArea, Point targetPoint, ll addingNumber)
{
    if(!(nowArea >> targetPoint)) return;

    int
    x1 = nowArea.startPoint.x,
    y1 = nowArea.startPoint.y,
    x2 = nowArea.endPoint.x,
    y2 = nowArea.endPoint.y,
    lenX = x2 - x1,
    lenY = y2 - y1;

    if(nowArea.startPoint == nowArea.endPoint)
    {
        segtree[index] += addingNumber;
        return;
    }

    int mx = (x1 + x2) / 2;
    int my = (y1 + y2) / 2;
    int nextIndex[4];
    FOR(i, 4) nextIndex[i] = index * 4 + (i + 1);
    Modify(nextIndex[0], Area(Point(x1, y1), Point(mx, my)), targetPoint, addingNumber);
    if(lenX > 0) Modify(nextIndex[1], Area(Point(mx+1, y1), Point(x2, my)), targetPoint, addingNumber);
    if(lenY > 0) Modify(nextIndex[2], Area(Point(x1, my+1), Point(mx, y2)), targetPoint, addingNumber);
    if(lenX > 0 && lenY > 0) Modify(nextIndex[3], Area(Point(mx+1, my+1), Point(x2, y2)), targetPoint, addingNumber);
    segtree[index] += addingNumber;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<ll> answers;

    FOR(y, N) FOR(x, N) cin >> numbers[y][x];

    SetSegtree(0, Area(Point(0, 0), Point(N-1, N-1)));

    FOR(m, M)
    {
        int w; cin >> w;
        if(w == 1)
        {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; x1--; y1--; x2--; y2--;
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            answers.push_back(FindSum(0, Area(Point(0, 0), Point(N-1, N-1)), Area(Point(x1, y1), Point(x2, y2))));
        }
        else
        {
            ll x, y, c; cin >> x >> y >> c; x--; y--;
            ll adding = c - numbers[y][x];
            numbers[y][x] = c;
            Modify(0, Area(Point(0, 0), Point(N - 1, N - 1)), Point(x, y), adding);
        }
    }

    int l = answers.size();
    FOR(m, l) cout << answers[m] << '\n';

    return 0;
}