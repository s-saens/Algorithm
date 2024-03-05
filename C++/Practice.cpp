#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, d, e, f, x, y; cin >> a >> b >> c >> d >> e >> f;

    int bottom = (b*d - a*e);
    if(bottom == 0) x = 0, y = 0;
    else
    {
        y = (c*d - a*f) / bottom;
        if(a == 0) x = (f - e*y) / d;
        else x = (c - b*y) / a;
    }

    cout << x << ' ' << y;

    return 0;
}