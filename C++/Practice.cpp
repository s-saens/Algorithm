#include <iostream>
#include <cmath>
#define FOR(i, e) for (int i = 0; i < e; ++i)
using namespace std;
int main()
{
    int X, Y, s = 0; cin >> Y >> X;
    int Z[Y][X];
    FOR(y, Y)FOR(x, X)
    {
        int n; cin >> n;
        Z[y][x] = n;
        s += 4 * n + 2;
        if (y > 0) s -= min(Z[y - 1][x], n) * 2;
        if (x > 0) s -= min(Z[y][x - 1], n) * 2;
    }
    cout << s;
    return 0;
}