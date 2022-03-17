#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long int

using namespace std;

struct Point
{
    ll x;
    ll y;
};

ll DistancePow2(Point &p1, Point &p2)
{
    ll dx = p1.x - p2.x;
    ll dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    Point p[3];
    for (int i = 0; i < 3; ++i)
    {
        cin >> p[i].x >> p[i].y;
    }

    ll d2[3];
    for (int i = 0; i < 3; ++i)
    {
        d2[i] = DistancePow2(p[i], p[(i + 1) % 3]);
    }

    sort(d2, d2 + 3);

    // 삼각형 아님
    if (sqrt(d2[0]) + sqrt(d2[1]) <= sqrt(d2[2]))
    {
        cout << 'X';
        return 0;
    }

    // 정삼각형
    if (d2[0] == d2[1] && d2[1] == d2[2])
    {
        cout << "JungTriangle";
        return 0;
    }

    bool is2 = false;
    if (d2[0] == d2[1] || d2[1] == d2[2])
    {
        is2 = true;
    }

    string answer;

    if (d2[0] + d2[1] == d2[2]) // 직각
    {
        answer = "Jikkak";
    }
    else if (d2[0] + d2[1] > d2[2]) // 예각
    {
        answer = "Yeahkak";
    }
    else if (d2[0] + d2[1] < d2[2]) // 둔각
    {
        answer = "Dunkak";
    }

    if (is2)
    {
        answer += '2';
    }

    answer += "Triangle";

    cout << answer;

    return 0;
}