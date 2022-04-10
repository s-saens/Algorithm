#include <iostream>
#include <cmath>
#define ll unsigned long long int
using namespace std;

struct Position
{
    ll x = 0;
    ll y = 0;
    Position(ll _x, ll _y)
    {
        x = _x;
        y = _y;
    }
    bool operator == (Position& p)
    {
        return this->x == p.x && this->y == p.y;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, r, c;
    cin >> N >> r >> c; // row:y좌표, column:x좌표
    ll pN = pow(2,N);

    Position lt = Position(0, 0);
    Position rb = Position(pN-1, pN-1);

    ll cnt = 0;
    ll size = pN;

    while(!(lt == rb))
    {
        ll size2D;
        if(size >= 4) size2D = size / 4 * size;
        else size2D = size * size / 4;
        // 왼쪽
        if(lt.x <= c && c <= rb.x - size/2)
        {
            rb.x -= size/2;
            // 위 : 1
            if(lt.y <= r && r <= rb.y - size/2)
            {
                rb.y -= size/2;
            }
            // 아래 : 3
            else
            {
                cnt += size2D * 2;
                lt.y += size/2;
            }
        }
        else
        {
            lt.x += size/2;
            // 위 : 2
            if (lt.y <= r && r <= rb.y / 2)
            {
                cnt += size2D * 1;
                rb.y -= size/2;
            }
            // 아래 : 4
            else
            {
                cnt += size2D * 3;
                lt.y += size/2;
            }
        }
        size /= 2;
    }

    cout << cnt;

    return 0;
}