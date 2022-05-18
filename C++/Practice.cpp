#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

#define ll long long int
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

struct V2
{
    ll x = 0;
    ll y = 0;

    V2 operator-(V2 v)
    {
        V2 newV;
        newV.x = x - v.x;
        newV.y = y - v.y;
        return newV;
    }

    short operator >> (V2 v) // 외적
    {
        ll c = (x * v.y) - (y * v.x);
        if(c < 0) return -1;
        if(c > 0) return 1;
        else return 0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    V2 P[3];
    FOR(i, 0, 3)
    {
        cin >> P[i].x >> P[i].y;
    }

    cout << ((P[1] - P[0]) >> (P[2] - P[1])) << "\n";

    return 0;
}