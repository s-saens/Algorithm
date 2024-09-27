#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

struct Vector2
{
    ll x, y;

    ll operator*(const Vector2 &other)
    {
        return this->x * other.x + this->y * other.y;
    }

    ll sqrLength(const Vector2 &other)
    {
        ll dx = this->x - other.x, dy = this->y - other.y;
        return dx * dx + dy * dy;
    }
};

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        Vector2 v[4];

        for (int i = 0; i < 4; ++i)
        {
            cin >> v[i].x >> v[i].y;
        }

        ll d[6];
        for (int i = 0; i < 4; ++i)
            d[i] = v[i].sqrLength(v[(i + 1) % 4]);
        d[4] = v[0].sqrLength(v[2]);
        d[5] = v[1].sqrLength(v[3]);

        sort(d, d + 6);

        cout << (d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5] ? 1 : 0) << '\n';
    }

    return 0;
}