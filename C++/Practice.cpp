#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define ull unsigned long long int

struct Point
{
    int x;
    int y;
};

double Distance(Point p1, Point p2)
{
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cout.precision(11);
    cout << fixed;

    Point points[3];

    for (int i = 0; i < 3; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    double dist[3];
    for (int i = 0; i < 3; ++i)
    {
        dist[i] = Distance(points[i], points[(i + 1) % 3]);
    }
    sort(dist, dist + 3);

    if ((dist[0] + dist[1]) - dist[2] <= 0.1e-10)
    {
        cout << dist[0] << ", " << dist[1] << ", " << dist[2] << "\n";
        cout << -1;
        return 0;
    }

    // if(points[0].x == points[1].x && points[0].x == points[2].x)
    // {
    //     cout << -1;
    //     return 0;
    // }
    // else if(points[0].y == points[1].y && points[0].y == points[2].y)
    // {
    //     cout << -1;
    //     return 0;
    // }
    // else
    // {
    //     int dx1 = points[1].x - points[0].x;
    //     int dx2 = points[2].x - points[1].x;
    //     int dy1 = points[1].y - points[0].y;
    //     int dy2 = points[2].y - points[1].y;

    //     double inc1, inc2;
    //     if(dx1 != 0)
    //     {
    //         inc1 = 1.0*dy1/dx1;
    //     }
    //     if(dx2 != 0)
    //     {
    //         inc2 = 1.0*dy2/dx2;
    //     }
    //     if(abs(inc1 - inc2) < 0.1e-11)
    //     {
    //         cout << -1;
    //         return 0;
    //     }
    // }

    cout << (dist[2] - dist[0]) * 2 << "\n";

    return 0;
}